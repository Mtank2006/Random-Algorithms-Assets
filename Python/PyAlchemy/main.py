import generate_qrcode
import api_pokemon

PROGRAMS = {
    "1": ("QR Code Demo", generate_qrcode.main),
    "2": ("API Demo", api_pokemon.main),
}

while True:
    print("\n=== Python Package Showcase ===")
    for key, (name, _) in PROGRAMS.items():
        print(f"{key}. {name}")
    print("0. Exit")

    choice = input("Select an option: ").strip()

    if choice == "0":
        break
    elif choice in PROGRAMS:
        PROGRAMS[choice][1]()
    else:
        print("Invalid choice.")