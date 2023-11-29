// get the button and element by their id
var button = document.getElementById("my-button");
var element = document.getElementById("my-element");

// add a click event listener to the button
button.addEventListener("click", function() {
    // toggle the "active" class on the element
    element.classList.toggle("active");
});