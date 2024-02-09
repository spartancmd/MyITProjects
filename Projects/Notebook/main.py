                            #############################################################
                            #                       Notebook                            #
                            # A programm to save and show someones name, age, address   #
                            # and number                                                #
                            # Programmed by Deniel                                      #
                            #############################################################


from Exceptions import *
from Notebook import Notebook
from TestCases import *

def main():
    TestCases.start_testing() 

    with Notebook('numbers.json') as notebook:
        print(Notebook.return_available_commands(), end='\n\n')
        while True:
            print("Type the command:")
            command  = input().split(" ")
            print() # to jump to a new line
            
            try:
                command_result = notebook.command_process(command)      # method which decides how to continue
                command_result.print()
                

            except Exit_programm:
                return 0
            except Command_not_valid as error_message:
                print(error_message, end='\n\n')
                print(Notebook.return_available_commands())
            except User_name_not_found as error_message:
                print(error_message)
            except:
                print("Unknown error ocurred")
                raise

            print() # to jump to a new line



if __name__ == "__main__":
    main()