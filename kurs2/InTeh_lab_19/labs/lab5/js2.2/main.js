let successArray = ['0', '2', '1', '3', '999'];
let array = ['2', '3', '0', '1', '999'];

function start() {
    for (let i = 0; i < array.length; i++) {
        $(`#element${i}`).html(`<img src="img/r${array[i]}.gif" id="${array[i]}">`);
    }
    setDraggable();
    setDroppable();
}

function setDraggable() {
    $('img').draggable();
}

function setDroppable() {
    $('img').droppable({
        drop: function(event, ui) {
            var dragId = ui.draggable.attr('id');
            var dropId = this.id;
            swapElements(dropId, dragId);
        }
    });
    $('body').droppable({
        drop: function(event, ui) {
            var dragId = ui.draggable.attr('id');
            var dropId = this.id;
            dropId == 999 ? swapElements(dragId, dragId) : swapElements(dropId, dragId);
        }
    });
}

function swapElements(dropId, dragId) {
    let indexOne = array.indexOf(dragId);
    let indexTwo = array.indexOf(dropId);

    let swap = array[indexOne];
    array[indexOne] = array[indexTwo];
    array[indexTwo] = swap;
    start();
    check();
}

function check() {
    for (let i = 0; i < successArray.length; i++) {
        if (successArray[i] != array[i]) {
            return;
        }
    }
    setTimeout('location.reload(true)', 2000000000);
}

function chet() {
	$(`#element${0}`).html(`<img src="img/r${array[0]}.gif" id="${array[5]}">`);
	$(`#element${1}`).html(`<img src="img/r${array[1]}.gif" id="${array[9]}">`);
	$(`#element${2}`).html(`<img src="img/r${array[2]}.gif" id="${array[7]}">`);
	$(`#element${3}`).html(`<img src="img/r${array[3]}.gif" id="${array[6]}">`);
}
function chet1() {
	$(`#element${0}`).html(`<img src="img/r${array[0]}.gif" id="${array[0]}">`);
	$(`#element${1}`).html(`<img src="img/r${array[1]}.gif" id="${array[1]}">`);
	$(`#element${2}`).html(`<img src="img/r${array[2]}.gif" id="${array[2]}">`);
	$(`#element${3}`).html(`<img src="img/r${array[3]}.gif" id="${array[3]}">`);
}