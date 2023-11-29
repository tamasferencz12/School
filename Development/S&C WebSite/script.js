function darkMode(Element){
    let x = document.getElementById(Element);
    x.style.backgroundColor = '#1c1c1c';
    x.style.color = '#d1d1d1';
}

function darkModeText(Element){
    let x = document.getElementById(Element);
    x.style.color = '#1c1c1c';
}

function lightMode(Element){
    let x = document.getElementById(Element);
    x.style.backgroundColor = 'white';
    x.style.color = 'black';
}

function lightModeText(Element){
    let x = document.getElementById(Element);
    x.style.color = 'white';
}

function transparent(Element1, Element2){
    let x = document.getElementById(Element1);
    let y = document.getElementById(Element2);
    x.style.display = "none";
    y.style.display = "flex";
}