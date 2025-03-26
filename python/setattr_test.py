class utils:
    def __init__(self, class_instance) -> None:
        print("this is a utility class")
        self.class_instance = class_instance
    
    def add_verbose_method(self):
        def verbose():
            print("the verbose() is being called")
        setattr(self.class_instance, "verbose", verbose)

class application:
    def __init__(self)  -> None:
        print("this is application class")
        self.utils = utils(self)
        
if __name__ == "__main__":
    APP = application()
    APP.utils.add_verbose_method()
    APP.verbose()