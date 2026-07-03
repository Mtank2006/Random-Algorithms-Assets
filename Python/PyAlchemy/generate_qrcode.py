import qrcode

def main():
    print("Running QR Code demo...")
    base_url = input("Enter the URL: ").strip()
    file_path = "/home/ayush-suman/Desktop/qrcode.png"

    qr = qrcode.QRCode(
        version=40,  # Size=21+4×(Version−1)
        box_size=10, # box_size=10 means each black/white square is 10 × 10 pixels. So final image size = (modules+2×border)×box_size
        border=4,
    )
    qr.add_data(base_url)

    img = qr.make_image()
    img.save(file_path)

    print("QR Code was generated")
    # for v in [1, 5, 10, 20, 40]:
    #     qr = qrcode.QRCode(version=v, box_size=5, border=4)
    #     qr.add_data("box_siu[jtydto")
    #     qr.make(fit=False)
    #     file_path_new = f"/home/ayush-suman/Desktop/v{v}.png"
    #     qr.make_image().save(file_path_new)

if __name__ == "__main__":
    main()