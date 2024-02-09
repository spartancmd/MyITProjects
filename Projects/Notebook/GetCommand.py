from Exceptions import *

class GetCommand:
    @staticmethod
    def is_valid(cmd, file): 
        if len(cmd) < 2: raise Command_not_valid("Error: Not enough arguments printed.")

        if cmd[1] == "names":
            #if len(cmd) > 2:
                #print("Arguments after \"names\" aren't necessary!", end='\n\n')
            return 1
        
        if len(cmd) <= 2: raise Command_not_valid("Error: Not enough arguments printed.")
        user_name = ' '.join(cmd[2 : len(cmd)])

        if user_name not in file: raise User_name_not_found(f"Error: No such user name \"{user_name}\".")

        return 1

    def person_info(jsonFile, name):
        user_name = name
        user_age = jsonFile[name]["age"]
        user_number = jsonFile[name]["number"]
        user_address = jsonFile[name]["address"]

        return {"name" : user_name, "number" : user_number, "address" : user_address, "age" : user_age}
        
    @staticmethod
    def names(jsonFile):
        return (name for name in jsonFile)
    
    @staticmethod
    def age(jsonFile, name):
        return jsonFile[name]["age"]

    @staticmethod
    def number(jsonFile, name):
        return jsonFile[name]["number"]

    @staticmethod
    def address(jsonFile, name):
        return jsonFile[name]["address"]