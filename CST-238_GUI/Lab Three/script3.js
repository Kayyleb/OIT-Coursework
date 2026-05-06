const puzzle = document.getElementById("puzzle");
const statusText = document.getElementById("status");
const shuffleBtn = document.getElementById("shuffleBtn");

let tiles = [0, 1, 2, 3, 4, 5, 6, 7, 8];
// 0 through 7 are image pieces, 8 will be the empty space

function createPuzzle() {
    puzzle.innerHTML = "";

    for (let i = 0; i < tiles.length; i++) {
        const tileValue = tiles[i];
        const tile = document.createElement("div");

        if (tileValue === 8) {
            tile.classList.add("tile", "empty");
        } else {
            tile.classList.add("tile");

            let row = Math.floor(tileValue / 3);
            let col = tileValue % 3;

            tile.style.backgroundPosition = `${-col * 100}px ${-row * 100}px`;
            tile.addEventListener("click", () => moveTile(i));
        }

        puzzle.appendChild(tile);
    }
}

function moveTile(index) {
    let emptyIndex = tiles.indexOf(8);

    if (isAdjacent(index, emptyIndex)) {
        let temp = tiles[index];
        tiles[index] = tiles[emptyIndex];
        tiles[emptyIndex] = temp;

        createPuzzle();
        checkWin();
    }
}

function isAdjacent(index1, index2) {
    let row1 = Math.floor(index1 / 3);
    let col1 = index1 % 3;
    let row2 = Math.floor(index2 / 3);
    let col2 = index2 % 3;

    return (
        (row1 === row2 && Math.abs(col1 - col2) === 1) ||
        (col1 === col2 && Math.abs(row1 - row2) === 1)
    );
}

function shufflePuzzle() {
    for (let i = 0; i < 100; i++) {
        let emptyIndex = tiles.indexOf(8);
        let possibleMoves = [];

        for (let j = 0; j < tiles.length; j++) {
            if (isAdjacent(j, emptyIndex)) {
                possibleMoves.push(j);
            }
        }

        let randomMove = possibleMoves[Math.floor(Math.random() * possibleMoves.length)];

        let temp = tiles[randomMove];
        tiles[randomMove] = tiles[emptyIndex];
        tiles[emptyIndex] = temp;
    }

    statusText.textContent = "Puzzle shuffled!";
    createPuzzle();
}

function checkWin() {
    let winningOrder = [0, 1, 2, 3, 4, 5, 6, 7, 8];

    for (let i = 0; i < tiles.length; i++) {
        if (tiles[i] !== winningOrder[i]) {
            return;
        }
    }

    statusText.textContent = "You solved the puzzle!";
}

shuffleBtn.addEventListener("click", shufflePuzzle);

createPuzzle();