from Exceptions import *
from Notebook import Notebook

def main():
    with Notebook("numbers.json") as notebook:
        print(Notebook.return_available_commands())

        while True:
            print("Type the command:")
            command  = input().split(" ")
            print() # to jump to a new line

            try:
                command_result = notebook.command_process(command)      # method which decides how to continue
                command_result.print()

                print() # to jump to a new line
            except Exit_programm:
                return 0
            except Command_not_valid as error_message:
                print(error_message)
                print(Notebook.return_available_commands())
            except User_name_not_found as error_message:
                print(error_message)
            except:
                print("Uknown error ocurred")
                raise



if __name__ == "__main__":
    main()