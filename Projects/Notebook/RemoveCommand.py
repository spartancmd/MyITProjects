from Exceptions import *

class RemoveCommand:
    def is_valid(cmd, file):
        if len(cmd) == 1: raise Command_not_valid("Error: Not enough arguments printed.")

        user_name = ' '.join(cmd[1 : len(cmd)])
        if user_name not in file: raise User_name_not_found(f"Error: No such user name: \"{user_name}\"")

        return 1
        
    @staticmethod
    def remove_user(jsonFile, name):
        jsonFile.pop(name)

        return 0