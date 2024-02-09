from abc import ABC, abstractmethod

class CommandResult(ABC):

    @abstractmethod
    def print(self):
        pass

    @abstractmethod
    def get_result(self): 
        pass

class GetCommandResult(CommandResult):
    def __init__(self, command, result=None):
        self.command = command
        self.result = result
        self.user_name = ' '.join(command[2 : len(command)])

    def print(self):
        if self.command[1] == "names":
            for name in self.result:
                print(name)

            return
        elif self.command[1] == "personinfo":
            print(f'Name: "{self.result["name"]}"; Number: "{self.result["number"]}"; Address: "{self.result["address"]}"; Age: "{self.result["age"]}"')
            
            return

        print(f"The {self.command[1]} of \"{self.user_name}\" is: {self.result}")
        
    def get_result(self): return self.result

class SetCommandResult(CommandResult):
    def __init__(self, command, result=None):
        self.option = command[1]
        self.result = result

        idx = command.index("value")
        self.user_name = ' '.join(command[2 : idx])
        self.new_val = ' '.join(command[idx + 1 : len(command)])

    def print(self): print(f"The {self.option} of \"{self.user_name}\" was successfully changed through: \"{self.new_val}\"")

    def get_result(self): return self.result

class RemoveCommandResult(CommandResult):
    def __init__(self, command, result=None):
        self.result = result
        self.user_name = ' '.join(command[1 : len(command)])

    def print(self): print(f"The person \"{self.user_name}\" was successfully removed.")

    def get_result(self): return self.result

class AddCommandResult(CommandResult):
    def __init__(self, command, result=None):
        self.result = result
        self.user_name = ' '.join(command[1 : len(command)])

    def print(self): print(f"The person \"{self.user_name}\" was successfully added.")

    def get_result(self): return self.result

class HelpCommandResult(CommandResult):
    def __init__(self, result=None):
        self.result = result

    def print(self): print(self.result)

    def get_result(self): return self.result