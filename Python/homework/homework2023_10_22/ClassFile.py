class File:

    def __init__(self, source, mode ):

        if source is None:                                     # Check if the options were typed
            print("Source and mode are undefined.")
        if mode is None:         
            print("Mode is undefined.")

        self.source_ = source                                   # Can I use "self.source", as well as mode, without the under line "_" here?
        self.mode_ = mode
        self.file = None


        if self.mode_ == 0:
            self.file = open(self.source_, encoding='utf-8')
        elif self.mode_ == 1:
            self.file = open(self.source_, "w")

        if self.file is None:
            print("An error ocurred while opening the file.")
    
    def is_opened_for_read(self):
        return self.mode_ == 0

    def read(self):
        return self.file.read() if self.is_opened_for_read() else None

    def write(self, text):
        if self.is_opened_for_read():
            return 1
        
        self.file.write(text)

        return 0
    
    def close(self):
        self.file.close()