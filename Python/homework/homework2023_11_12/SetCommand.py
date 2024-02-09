from Exceptions import *

class SetCommand: #SetСommand:
    @staticmethod
    def is_valid(cmd, file):
        if len(cmd) <= 3: raise Command_not_valid("Not enough arguments printed.")
        if "value" not in cmd: raise Command_not_valid("The word \"value\" is missing in the command.")

        idx = cmd.index("value")
        user_name = cmd[1 : idx]
        if user_name not in file: raise User_name_not_found(f"No such user name: \"{user_name}\"")

        return 1

    @staticmethod
    def name(file, user, new_value):
        bfr = file.pop(user)
        file[new_value] = bfr

    @staticmethod
    def age(file, user, new_value):
        file[user]["age"] = new_value

    @staticmethod
    def number(file, user, new_value):
        file[user]["number"] = new_value

    @staticmethod
    def address(file, user, new_value):
        file[user]["address"] = new_value





