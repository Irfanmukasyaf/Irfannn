<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bulan</title>
</head>
<body>
    <h1>Cetak Bulan</h1>
    <label for="bulanInput">Masukkan angka (1-12): </label>
    <input type="number" id="bulanInput" min="1" max="12">
    <button onclick="cetakBulan()">Cetak Bulan</button>
    <p id="hasilBulan"></p>

    <script>
        function cetakBulan() {
            const bulan = document.getElementById('bulanInput').value;
            let namaBulan;

            switch (bulan) {
                case '1': namaBulan = 'Januari'; break;
                case '2': namaBulan = 'Februari'; break;
                case '3': namaBulan = 'Maret'; break;
                case '4': namaBulan = 'April'; break;
                case '5': namaBulan = 'Mei'; break;
                case '6': namaBulan = 'Juni'; break;
                case '7': namaBulan = 'Juli'; break;
                case '8': namaBulan = 'Agustus'; break;
                case '9': namaBulan = 'September'; break;
                case '10': namaBulan = 'Oktober'; break;
                case '11': namaBulan = 'November'; break;
                case '12': namaBulan = 'Desember'; break;
                default: namaBulan = 'Input tidak valid!'; break;
            }

            document.getElementById('hasilBulan').innerText = namaBulan;
        }
    </script>
</body>
</html>