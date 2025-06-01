from rich.console import Console
from rich.text import Text

console = Console()

def square(size, color):
    for _ in range(size):
        console.print(Text("■ " * size, style=color))

def rectangle(width, height, color):
    for _ in range(height):
        console.print(Text("■ " * width, style=color))

def triangle(height, color):
    for i in range(1, height + 1):
        console.print(Text("■ " * i, style=color))

def circle(radius, color):
    for i in range((radius * 2) + 1):
        line = ""
        for j in range((radius * 2) + 1):
            x = i - radius
            y = j - radius
            if x * x + y * y <= radius * radius:
                line += "■ "
            else:
                line += "  "
        console.print(Text(line, style=color))

while True:
    console.print("\n[bold]Choose a shape to display:[/bold]")
    console.print("1 - Square\n2 - Rectangle\n3 - Triangle\n4 - Circle\n5 - Exit")
    choice = input("Choice (1-5): ")

    if choice == "1":
        size = int(input("Square size: "))
        color = input("Color (e.g., red, green, blue, yellow): ")
        square(size, color)
    elif choice == "2":
        width = int(input("Rectangle width: "))
        height = int(input("Rectangle height: "))
        color = input("Color: ")
        rectangle(width, height, color)
    elif choice == "3":
        height = int(input("Triangle height: "))
        color = input("Color: ")
        triangle(height, color)
    elif choice == "4":
        radius = int(input("Circle radius: "))
        color = input("Color: ")
        circle(radius, color)
    elif choice == "5":
        console.print("[bold green]Goodbye![/bold green]")
        break
    else:
        console.print("[bold red]Unknown option. Please try again.[/bold red]")