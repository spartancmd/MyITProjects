import json

from GetCommand import GetCommand
from AddCommand import AddCommand
from RemoveCommand import RemoveCommand
from SetCommand import SetCommand

class Notebook:
    def __init__(self, path):
        self.path_ = path

        with open(path, "r") as jsonFile:
            try:
                self.settings = json.load(jsonFile)       # self.settings now contains data from the file
            except json.JSONDecodeError:
                print("An error occured: \"json.JSONDecodeError\"")
            except:
                print("An error occurred while opening the file.")

    @staticmethod
    def return_available_commands():
        lines = [
        "This options are available:\n",
        "get\tset\tremove\tadd\thelp [h]\tquit [q]\n",
        "Possible options for get:\nnames; personinfo; age; number; address:\n",
        "To use get, type: get [option] [person name]\n",
        "Possible options for set:\nname; age; number; address:\n",
        "To use set, type: set [option] [person name] value [new value]\n",
        "To use remove, type: remove [person name]\n",
        "To use add, type: add [person name]\n"
    ]

        listed_commands = ''.join(lines)


        return listed_commands

    def get_file_content(self): return self.settings

    def upload_changes(self):
        jsonFile = open(self.path_ , "w")
        json.dump(self.settings, jsonFile, indent = 4)

        jsonFile.close()

    def get_redirect(self, command):
        second_option = command[1]
        user_name = ' '.join(command[2 : len(command)])

        if second_option == "names":
            return GetСommand.names(self.settings)
        elif second_option == "number":
            return GetСommand.number(self.settings, user_name)
        elif second_option == "age":
            return GetСommand.age(self.settings, user_name)
        elif second_option == "address":
            return GetСommand.address(self.settings, user_name)
        elif second_option == "personinfo":
            return GetСommand.person_info(self.settings, user_name)

    def set_redirect(self, command):
        second_option = command[1]
        value_idx = command.index("value")
        user_name = ' '.join(command[2 : value_idx])
        new_value = ' '.join(command[value_idx + 1 : len(command)])

        if second_option == "name":
            SetCommand.name(self.settings, user_name, new_value)
        elif second_option == "number":
            SetCommand.number(self.settings, user_name, new_value)
        elif second_option == "age":
            SetCommand.age(self.settings, user_name, new_value)
        elif second_option == "address":
            SetCommand.address(self.settings, user_name, new_value)

        return 0

    def command_process(self, command):

        if command[0] == "add":
            user_name = ' '.join(command[1: len(command)])

            if AddCommand.is_valid(command, self.settings):
                result = AddCommand.add_user(self.settings, user_name)

                return CommandResult(command, result)

        elif command[0] in ("quit", "q"): raise Exit_programm

        elif command[0] in ("help", "h"):
            result =  Notebook.return_available_commands()

            return CommandResult(command, result)

        elif len(self.settings) == 0: raise User_name_not_found("No users in the file.")    # Check if there'rent any users in the file

        elif command[0] == "set":

            if SetCommand.is_valid(command, self.settings):
                result = self.set_redirect(command)   # calls a function where the right method is called

                return CommandResult(command, result)
        elif command[0] == "get":
            if GetCommand.is_valid(command, self.settings):
                result = self.get_redirect(command)  # calls a function where the right method is called

                return CommandResult(command, result)
        elif command[0] == "remove":
            user_name = ' '.join(command[1: len(command)])

            if RemoveCommand.is_valid(command, self.settings):
                result = RemoveCommand.remove_user(self.settings, user_name)

                return CommandResult(command, result)



    def __enter__(self): return self

    def __exit__(self, exc_type, exc_val, exc_tb):
            self.upload_changes()

