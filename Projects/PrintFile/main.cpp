#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// -l, --lines=n вывести только n (только положительное) первых(последних) строк файл (необязательный аргумент, по-умолчанию выводим все)
// -t, --tail вывод n последний строк файла (необязательный аргумент)
// -d, --delimiter=c символ по которому определяется конец строки (нeобязательный, по-умолчанию '\n')

struct Parameters 
{
    unsigned long lines = ULONG_MAX;   
    bool tail = false;
    std::string delimiter = "\n";
};

Parameters process_cl_args(unsigned argc, std::string* args)   // returns a struct objects that contains needed parameters that were defined by the command line arguments
{
    Parameters params{};

    for (unsigned i = 1; i < argc; i++) // We start from 1 to ignore the programm name.
    {
        if (args[i] == "-l")
            params.lines = std::stoi(args[++i]); // ++i because we need to move to the next element of the array right now // atoi() to make the char* to int
        else if ((args[i] == "-t") || (args[i] == "--tail"))
            params.tail = true;
        else if (args[i] == "-d")
            params.delimiter = args[++i];        
        else if(args[i].find("--lines=") != std::string::npos)
            params.lines = std::stoi(args[i].substr(8));   // substr removes the left part from idx + 1 // the symbol = has the idx 7, so we remove everything left from idx 7 + 1 -> 8
        else if(args[i].find("--delimiter=") != std::string::npos)
            params.delimiter = args[i].substr(12); // symbol = has idx 11 -> 11 + 1 = 12
    }

    return params;
}

// unsigned long int get_cnt_lines_in_file(std::ifstream& file)
// {
//     if(!file.is_open()) // If the file is not opened
//         return 0;       // there are no lines

//     unsigned lines = 1;
//     char ch = 0;
//     std::streampos start_pos_of_file = file.tellg();

//     while(file.get(ch))
//     {
//         if (ch == '\n')
//             lines++;
//     }
    
//     file.clear();
//     file.seekg(start_pos_of_file);

//     return lines;
// }

void print_file_from_end(Parameters& params, std::ifstream& file)
{
    unsigned long lines_in_file = 4 /*get_cnt_lines_in_file(file)*/;
    std::string read_line{};


    for(auto line_cnt = 1; (line_cnt <= (lines_in_file - params.lines)) && getline(file, read_line); line_cnt++); // skip the first unneeded lines (= "lines in the whole file" - "the amount of lines from bottom of the file")
                                                                                                                            // or until we reach the end of the file
    while(getline(file, read_line))     // Printing the last lines in the console
        std::cout << read_line << params.delimiter;
}

void print_file(Parameters& params, std::ifstream& file)
{
    std::string read_line{}; // line where the interpreted line from the file gets saved

    for(auto line_cnt = 1; line_cnt <= params.lines && getline(file, read_line); line_cnt++)
        std::cout << read_line << params.delimiter;

}

int process_params(Parameters& params, std::string path)
{
    if(params.tail) 
    {
        std::ifstream file{path};

        if(!file.is_open()) // if returns false print error and leave
        {
            std::cerr << "An error occured while opening the file!" << std::endl;
            return 1;   
        }
        print_file_from_end(params, file);
        
        file.close();
    }
    else 
    {
        std::ifstream file{path};

        if(!file.is_open()) // if returns false print error and leave
        {
            std::cerr << "An error occured while opening the file!" << std::endl;
            return 1;   
        }

        print_file(params, file);

        file.close();
    }

    return 0;
}

std::string* parse_cla(int argc, char* argv[])
{
    std::string* args = new std::string[argc]; 

    for (unsigned i = 0; i < argc; i++)
        args[i] = argv[i];
    
    return args;
}

int check_cla(std::string* args)
{
    return 0;
}

int main(int argc, char* argv[])
{
    std::string* args = parse_cla(argc, argv); // should return arguments in string format // cla - command line arguments 
    std::string path = args[argc - 1];
    Parameters params{};

    if (check_cla(args)) // returns 0 if everything is fine and 1 if not
    {
        std::cerr << "Error: Launched the programm with wrong arguments." << std::endl;
        std::cout << "type: printFile.exe [options] <path of the text file>" << std::endl;
        std::cout << "options:\n -l [lines] / --lines=[lines]\t sets the number of lines\n-d [symbol] / --delimiter=[symbol]\t sets the delimeter\n-t / --tail\t print file from the bottom" << std::endl;

        return 1;
    }
    
    params = process_cl_args(argc - 1, args); // args.length() - 1 because we don't need the file path that is at the end

    process_params(params, path);

    delete[] args;
    return 0;
}