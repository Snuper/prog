from cx_Freeze import setup, Executable

setup(
    name = "UcPrac",
    version = "0.1",
    description = "Blackjack",
    executables = [Executable("UcPrac.py")]
)
