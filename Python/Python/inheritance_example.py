import sys

from PIL import Image
from PIL.ImageQt import ImageQt

from PyQt6.QtWidgets import QApplication, QMainWindow, QLabel, QScrollArea, QFileDialog, QWidget, QVBoxLayout, QLineEdit, QHBoxLayout, QComboBox, QCheckBox
from PyQt6.QtGui import QPixmap, QAction
from PyQt6.QtCore import Qt, pyqtSlot

def print_hello():
    print("Hello!")

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.main_widget = QWidget()

        self.main_layout = QHBoxLayout()
        self.main_widget.setLayout(self.main_layout)

        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)
        self.scroll_area.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAsNeeded)
        self.scroll_area.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAsNeeded)
        self.main_layout.addWidget(self.scroll_area)

        self.image_label = QLabel(self)
        self.scroll_area.setWidget(self.image_label)

        self.__init_top_menu()

        self.main_layout.setStretchFactor(self.scroll_area, 10)

        self.setCentralWidget(self.main_widget)

        self.setWindowTitle("GOTOIMAGE")
        self.showMaximized()

    def __init_top_menu(self):
        self.file_menu = self.menuBar().addMenu("&File")

        self.open_file_action = QAction("&Open", self)
        self.open_file_action.triggered.connect(print_hello)
        self.file_menu.addAction(self.open_file_action)

        self.save_file_action = QAction("&Save", self)
        self.save_file_action.triggered.connect(print_hello)
        self.file_menu.addAction(self.save_file_action)

def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
