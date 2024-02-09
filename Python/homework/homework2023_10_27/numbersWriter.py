                    #---------------------------------------------------------------------------#
                    # Programmname: numbersWriter                                               #
                    # Function: Is a editor of a Notebook in a json file called "numbers.json"  #
                    # Programmed by Deniel                                                      #
                    #---------------------------------------------------------------------------#

import json

def getCommand(option, jsonFile):
    if option[1] == "names":
        cnt = 0

        for key in jsonFile:
            print(key)
            cnt += 1

        if cnt == 0:
            print("The file doesn't have registrated users")

        return
    
    whatToGet = option[1]
    userName = ' '.join(option[2: len(option)])

    if userName not in jsonFile:
        print(f"No such name \"{userName}\"")
        return 

    print(f"The {whatToGet} of {userName} is: {jsonFile[userName][whatToGet]}")


def setCommand(option, jsonFile):
    
    if "value" not in option:                     
        print("Error: \"value\" is missing in the command!")
        print('Please type "value" after the name of the user name and then the new definition')

        return
    
    which_key_to_change = option[1]
    idx = option.index("value")         # Index of the element "value" for further process
    userName = ' '.join(option[2: idx])
    through_what_to_change = ' '.join(option[idx + 1: len(option)])

    if userName not in jsonFile:
        print(f"No such name \"{userName}\"")
        return 

    if which_key_to_change == "name":
        bfrForDict = jsonFile.pop(userName, 1)

        if bfrForDict == 1:
            print(f'Error: User name "{userName}" not found')

            return

        jsonFile[through_what_to_change] = bfrForDict
    else:
        jsonFile[userName][which_key_to_change] = through_what_to_change

    print("Changes have been made successfully!")
    print(f'The {which_key_to_change} of {userName} has been changed through "{through_what_to_change}".')

    return

def exitFunction(jsonFile):

    file = open("numbers.json", "w")
    json.dump(jsonFile, file, indent = 4)
    file.close()

    exit(0)

def addCommand(option, jsonFile):
    newUser = ' '.join(option[1: len(option)])

    if newUser in jsonFile:
        print(f"There already is a user with such user name \"{newUser}\"")
        
        return
    
    jsonFile[newUser] = {"number": None, "address": None, "age": None}

    print("Changes have been made successfully!")
    print(f"The user name \"{newUser}\" has been added.")

def rmCommand(option, jsonFile):
    userName = ' '.join(option[1 : len(option)])

    if userName not in jsonFile:
        print(f"No such name \"{userName}\"")

        return

    jsonFile.pop(userName)

    print("Changes have been made successfully!")
    print(f"The user \"{userName}\" was deleted.")

def possible_opt_for_set_and_get(option):
    print(f'For "{option[0]}" there\'re only these options available:')

    if option[0] == "get":
        print("names,", end = ' ')
    elif option[0] == "set":
        print("name,", end = ' ')

    print("number, address and age.")

def checkOption(option):

    if len(option) == 0:
        print("Error: No command printed")

        return 1

    if option[0] in ("add", "remove") and len(option) == 1:
        print(f"Nothing typed after \"{option[0]}\" command")
        print(f"Type the name of the user after the \"{option[0]}\" command.")

        return 1
    
    if option[0] not in ("set", "get", "quit", "add", "remove"):
        print(f'The option "{option[0]}" isn\'t a possible option.' )
        print('Only options "set", "quit", "add", "remove" and "get" are available')
        
        return 1
    if option[0] in ("set", "get", "add", "remove") and len(option) == 1:
        print(f"Nothing typed after \"{option[0]}\" command")

        possible_opt_for_set_and_get(option)

        return 1
    

    return 0

def greetingMessage():
    print("Available commands:")
    print("get\tset\tadd\tremove\tquit")
    print("Next to them type the possible option for each one.\nTo know out which are available, type one of the upper command and you'll see\ntheir possible option.", end = '\n\n')


def main():

    file = open("numbers.json", "r")        #
    jsonFile = file.read()                  #   Opening of the .json file in this programm
    file.close()                            #    
                                            
    jsonFile = json.loads(jsonFile)         

    greetingMessage()

    while True:
        print("Type the command")

        option = input().split()
        print() # to jump to a new line

        if checkOption(option) != 0:            # Check if the command was printed correctly
            print() # to jump to a new line
            continue
        elif option[0] in ("quit", "q"):
            exitFunction(jsonFile)
        elif option[0] == "get":
            getCommand(option, jsonFile)
        elif option[0] == "set":
            setCommand(option, jsonFile)
        elif option[0] == "add":
            addCommand(option, jsonFile)
        elif option[0] == "remove":
            rmCommand(option, jsonFile)

        print()         # To jump to a new line

if __name__ == "__main__":
    main()