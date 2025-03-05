<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kalkulator Luas Segitiga dan Volume Kubus</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        input {
            margin: 5px 0;
            padding: 10px;
            width: 200px;
        }
        button {
            padding: 10px 15px;
            margin-top: 10px;
        }
        h2 {
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <h1>Kalkulator Luas Segitiga dan Volume Kubus</h1>

    <h2>Luas Segitiga</h2>
    <label for="alas">Alas (a):</label>
    <input type="number" id="alas" placeholder="Masukkan alas" required>
    <br>
    <label for="tinggi">Tinggi (t):</label>
    <input type="number" id="tinggi" placeholder="Masukkan tinggi" required>
    <br>
    <button onclick="hitungLuasSegitiga()">Hitung Luas Segitiga</button>
    <p id="hasilLuasSegitiga"></p>

    <h2>Volume Kubus</h2>
    <label for="sisi">Sisi (s):</label>
    <input type="number" id="sisi" placeholder="Masukkan sisi" required>
    <br>
    <button onclick="hitungVolumeKubus()">Hitung Volume Kubus</button>
    <p id="hasilVolumeKubus"></p>

    <script>
        function hitungLuasSegitiga() {
            const alas = parseFloat(document.getElementById('alas').value);
            const tinggi = parseFloat(document.getElementById('tinggi').value);
            const luas = 0.5 * alas * tinggi;
            document.getElementById('hasilLuasSegitiga').innerText = 'Luas Segitiga: ' + luas + ' satuan persegi';
        }

        function hitungVolumeKubus() {
            const sisi = parseFloat(document.getElementById('sisi').value);
            const volume = sisi * sisi * sisi;
            document.getElementById('hasilVolumeKubus').innerText = 'Volume Kubus: ' + volume + ' satuan kubik';
        }
    </script>
</body>
</html>