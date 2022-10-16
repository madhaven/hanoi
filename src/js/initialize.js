towers = document.getElementsByClassName('tower')
number_of_blocks = 4 // parseInt(prompt('Select the number of Hanoi blocks that you want'))
data = [
    [3, 2, 1, 0],
    [],
    []
]
moves = 0
document.getElementById("count").innerText = moves
document.getElementById("stopwatch").innerHTML = '00:00';
updateUI()