from SetCommand import SetCommand
from GetCommand import GetCommand
from AddCommand import AddCommand
from RemoveCommand import RemoveCommand
from Exceptions import *
from CommandResult import *
from Notebook import Notebook
    
class TestCases:
    @staticmethod
    def test_GetCommand():
        cls = GetCommand

        # Testing method .person_info

        file = {"testUser" : {"age" : 22, "number" : 1234, "address" : "idk"}}
        assert GetCommand.person_info(file, "testUser") == {"name" : "testUser", "number" : 1234, "address" : "idk", "age" : 22}    # Checks if the returned dict is right
        
        # Testing method .names

        file = {"testUser1": None, "testUser2": None, "testUser3": None}
        assert tuple(GetCommand.names(file)) == ("testUser1", "testUser2", "testUser3")
        
        # Testing methods .age, .number and .address

        file = {"testUser" : {"age" : 22, "number" : 1234, "address" : "abcde"}}
        assert GetCommand.age(file, "testUser") == 22
        assert GetCommand.number(file, "testUser") == 1234
        assert GetCommand.address(file, "testUser") == "abcde"

        # Testing method .is_valid

        file = {"name" : None}
        cmd = ["get", "names"]
        assert GetCommand.is_valid(cmd, file) == 1
        cmd = ["get", "names", "131441141441"]
        assert GetCommand.is_valid(cmd, file) == 1
        cmd = ["get"]
        try:
            GetCommand.is_valid(cmd, file)
            assert False # If is_valid doesn't raise an exception, assert should be called
        except Command_not_valid: pass 

        cmd = ["get", "asdasdasdad"]
        try:
            GetCommand.is_valid(cmd, file)
            assert False
        except Command_not_valid: pass
    
    @staticmethod
    def test_SetCommand():
        # Testing method .name 
        file = {"user": {"age": "21", "number": "1234", "address": "test"}}
        user_name = "user"
        new_user_name = "new name"
        SetCommand.name(file, user_name, new_user_name)
        assert file == {"new name": {"age": "21", "number": "1234", "address": "test"}}

        # Testing method .age
        file = {"user": {"age": "21", "number": "1234", "address": "test"}}
        user = "user"
        new_val = "30"
        SetCommand.age(file, user, new_val)
        assert file == {"user": {"age": "30", "number": "1234", "address": "test"}}

        # Testing method .number
        file = {"user": {"age": "21", "number": "1234", "address": "test"}}
        user = "user"
        new_val = "22"
        SetCommand.number(file, user, new_val)
        assert file == {"user": {"age": "21", "number": "22", "address": "test"}}

        # Testing method .address
        file = {"user": {"age": "21", "number": "1234", "address": "test"}}
        user = "user"
        new_val = "new address"
        SetCommand.address(file, user, new_val)
        assert file == {"user": {"age": "21", "number": "1234", "address": "new address"}}

        # Testing method .is_valid
        file = {"user": {"age": "21", "number": "1234", "address": "test"}}
        
        try: 
            cmd = "set foo foo".split()
            SetCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except Command_not_valid: pass

        try:
            cmd = "set foo foo foo".split()
            SetCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except Command_not_valid: pass 

        try:
            cmd = "set [option] another user value foo".split()
            SetCommand.is_valid(cmd, file)
            assert False # Didn't return an exception
        except User_name_not_found: pass

        cmd = "set [option] user value foo".split()
        assert SetCommand.is_valid(cmd, file) == 1

    @staticmethod
    def test_AddCommand():
        # Testing method .add_user
        file = {}
        new_name = "New User"
        returned_val = AddCommand.add_user(file, new_name)
        assert not returned_val
        assert file == {"New User": {"number" : None, "address" : None, "age" : None}}

        # Testing method .is_valid
        file = {"user": {"number" : "foo", "address" : "foo", "age" : "foo"}}
        
        try: 
            cmd = ["add"]
            AddCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except Command_not_valid: pass
        
        try:
            cmd = "add user".split()
            AddCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except User_name_not_found: pass

        cmd = "add new User".split()
        assert AddCommand.is_valid(cmd, file) == 1

    @staticmethod
    def test_RemoveCommand():        
        # Test method .remove_user
        file = {
        "user name": {"age": "foo", "number": "foo", "address": "foo"},
        "user": {"age": "foo", "number": "foo", "address": "foo"}
        }
        user = "user name"
        returned_val = RemoveCommand.remove_user(file, user)
        assert not returned_val
        assert file == {"user": {"age": "foo", "number": "foo", "address": "foo"}}
        
        # Test method .is_valid
        file = {"user name": {"age": "foo", "number": "foo", "address": "foo"}}
        
        try:
            cmd = ["remove"]
            RemoveCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except Command_not_valid: pass

        try:
            cmd = "remove another user".split()
            RemoveCommand.is_valid(cmd, file)
            assert False  # Didn't return an exception
        except User_name_not_found: pass

        cmd = "remove user name".split()
        assert RemoveCommand.is_valid(cmd, file) == 1

    @staticmethod
    def start_testing():
        # Basic methods
        TestCases.test_GetCommand()
        TestCases.test_SetCommand()
        TestCases.test_AddCommand()
        TestCases.test_RemoveCommand()
        # Bigger methods (declined)
        # TestCases.test_CommandResult()