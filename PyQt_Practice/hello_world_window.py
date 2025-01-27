import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout
from PyQt5.QtGui import QFont

def main():
    # Create an instance of QApplication
    app = QApplication(sys.argv)

    # Create a QWidget (the main window)
    window = QWidget()
    window.setWindowTitle('Hello PyQt5')
    window.resize(1920, 1080)  # Set the window size
    window.move(100, 100)


    # Create a QLabel to display "Hello, World!"
    hello_label = QLabel("Hello, World!", window)
    hello_label.setBaseSize(15, 15)

    # Create new font object
    font = QFont()
    font.setBold(True)
    font.setPointSize(25)

    layout = QVBoxLayout()
    layout.activate()

    # Adjust font for label
    hello_label.setFont(font)
    hello_label.move(5,5)

    window.show()  # Show the window

    # Run the application's event loop
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()