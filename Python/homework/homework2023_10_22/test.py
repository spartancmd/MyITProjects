from ClassFile import File

def testCases():

    f = File("testTxt.txt", 1) # To restore the file
    f.write("Hello\nBruf\nTest")
    f.close()

    file = File("testTxt.txt", 0)          # 0 - Read mode    1 - Write mode

    assert file.is_opened_for_read() == True
    assert file.read() == "Hello\nBruf\nTest"
    assert file.write("Bla bla bla") == 1

    file.close()

    file = File("testTxt.txt", 1)

    assert not file.is_opened_for_read() 
    assert file.read() is None
    
    file.write("Bla bla") # Assert for that is where the file is read next time

    file.close()

    file = File("testTxt.txt", 0)    
    assert file.read() == "Bla bla"

    file.close()


    f = File("testTxt.txt", 1)   
    f.write("Hello\nBruf\nTest")
    f.close()
