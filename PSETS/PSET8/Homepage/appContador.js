var currentNumberWrapper = document.getElementById('currentNumber');
var currentNumber = 0;


sumar.addEventListener("click", increment); 
restar.addEventListener("click", decrement); 


function decrement() {
    if (currentNumber == 0) {
        document.getElementById("currentNumber").style.color = "red";
        restar.removeEventListener("click");  
           
    } else {
        currentNumber = currentNumber - 1;
        currentNumberWrapper.innerHTML = currentNumber;
    }    
}

function increment() {
    if (currentNumber == 10) {
        sumar.removeEventListener("click");
        
    } else {
        currentNumber = currentNumber + 1;
        currentNumberWrapper.innerHTML = currentNumber;
    }
}