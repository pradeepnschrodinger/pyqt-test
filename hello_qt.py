# python -m pip install pyqt6
# python hello_qt.py

from PyQt6 import QtWidgets

app = QtWidgets.QApplication([])
btn = QtWidgets.QPushButton("This is a button")

btn.show()
app.exec()