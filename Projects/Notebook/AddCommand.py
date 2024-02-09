from Exceptions import *

class AddCommand:
    @staticmethod
    def is_valid(cmd, file):
        if len(cmd) == 1: raise Command_not_valid("Error: Not enough arguments printed.")
        user_name = ' '.join(cmd[1 : len(cmd)])
        if user_name in file: raise User_name_not_found(f"Error: The person \"{user_name}\" is already registered.")

        return 1

    @staticmethod
    def add_user(jsonFile, name):
        jsonFile[name] = {"number" : None, "address" : None, "age" : None}

        return 0