import requests

def get_pokemon_info(name):
    base_url = "https://pokeapi.co/api/v2/"
    url = f"{base_url}/pokemon/{name}"
    response = requests.get(url)
    # print(response)

    if response.status_code == 200:
        # print("Data retrieved")
        pokemon_data = response.json()
        return pokemon_data
    else:
        print(f"Failed to retrieve data {response.status_code}")
        return None

def main():
    print("Running API demo...")
    # API code goes here
    # pokemon_name = "bulbasaur"
    # pokemon_name = "Typhlosion"
    pokemon_name = "Pikachu"
    pokemon_info = get_pokemon_info(pokemon_name)

    if pokemon_info:
        print(f"Name: {pokemon_info["name"].capitalize()}")
        print(f"Id: {pokemon_info["id"]}")
        print(f"Height: {pokemon_info["height"]}")
        print(f"Weight: {pokemon_info["weight"]}")
        # print(f"Name: {pokemon_info["ios639]"].capitalize()}")


if __name__ == "__main__":
    main()