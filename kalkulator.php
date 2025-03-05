<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kalkulator Sederhana</title>
</head>
<body>
    <h1>Kalkulator Sederhana</h1>
    <input type="number" id="angka1" placeholder="Angka 1">
    <input type="number" id="angka2" placeholder="Angka 2">
    <select id="operasi">
        <option value="+">+</option>
        <option value="-">-</option>
        <option value="*">*</option>
        <option value="/">/</option>
    </select>
    <button onclick="hitung()">Hitung</button>
    <p id="hasilKalkulator"></p>

    <script>
        function hitung() {
            const angka1 = parseFloat(document.getElementById('angka1').value);
            const angka2 = parseFloat(document.getElementById('angka2').value);
            const operasi = document.getElementById('operasi').value;
            let hasil;

            switch (operasi) {
                case '+': hasil = angka1 + angka2; break;
                case '-': hasil = angka1 - angka2; break;
                case '*': hasil = angka1 * angka2; break;
                case '/': 
                    if (angka2 !== 0) {
                        hasil = angka1 / angka2; 
                    } else {
                        hasil = 'Tidak bisa dibagi dengan nol!';
                    }
                    break;
                default: hasil = 'Operasi tidak valid!'; break;
            }

            document.getElementById('hasilKalkulator').innerText = hasil;
        }
    </script>
</body>
</html>