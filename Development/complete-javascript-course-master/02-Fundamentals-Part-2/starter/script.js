'use strict';
/*
let hasDriversLicense = false;
const passTest = true;

if(passTest) hasDriversLicense = true;
if(hasDriversLicense) console.log('I can drive!');

// const interface = 'Audio';
// const private = 542;
// const if = 24;


function logger(){
    console.log('My name is Tamas');
}

//calling  / running / invoking function
logger();
logger();
logger();

function fruitProcessor(apples, oranges){
    const juice = `Juice with ${apples} apples and ${oranges} oranges.`;
    return juice;
}

const appleJuice = fruitProcessor(3, 8);
console.log(appleJuice);

const appleOrangeJuice = fruitProcessor(2, 4);
console.log(appleOrangeJuice);

//FUNCTION DECLARATION
function calcAge1(birthYear){
    return 2037 - birthYear;
}

const age1 = calcAge1(2004);

//FUNCTION EXPRESSION
const calcAge2 = function (birthYear){
    return 2037 - birthYear;
}

const age2 = calcAge2(2005);
console.log(age1, age2);


//ARROW FUNCTION
const calcAge3 = birthYear => 2037 - birthYear;
const age3 = calcAge3(2008);
console.log(age3);

const yearsUnitRetirement = (birthYear,firstName) => {
    const age = 2037 - birthYear;
    const retirement = 65 - age;
    //return retirement;
    return `${firstName} retires in ${retirement} years`;

}

console.log(yearsUnitRetirement((2000),'Tamas'));
console.log(yearsUnitRetirement((2008),'Bob'));


function cutFruitPieces(fruit){
    return fruit * 4;
}

function fruitProcessor(apples, oranges){
    const applePieces=cutFruitPieces(apples);
    const orangesPieces=cutFruitPieces(oranges);

    const juice = `Juice with ${applePieces} pieces of apples and ${orangesPieces} orange pieces of orange.`;
    return juice;
}

console.log(fruitProcessor(2, 3));

const calcAge = function(year){
    return 2037 - year;
}

const yearsUnitRetirement = function (birthYear,firstName){
    const age = calcAge(birthYear);
    const retirement = 65 - age;

    if(retirement > 0){
        console.log(`${firstName} retires in ${retirement} years!`)
        return retirement;
    }else{
        console.log(`${firstName} has already retired!`);
        return -1;
    }
    //return `${firstName} retires in ${retirement} years`;

}

console.log(yearsUnitRetirement(1991, 'Jonas'));
console.log(yearsUnitRetirement(1950, 'Mike'));


const calcAvarage =  (score1, score2, score3) => 1(score1 + score2 + score3)/3;

const dolphinsAvarage = calcAvarage(44, 23, 71);
const koalasAvarage = calcAvarage(65, 54, 67);

console.log(dolphinsAvarage);
console.log(koalasAvarage);

const teamAvarage = (x, y) =>  `Both team's avarage score is ${(x + y)/2}`;

console.log(teamAvarage(dolphinsAvarage,koalasAvarage));

const checkWinner = (x,nameX,y,nameY) => {
    if(x == y){
        return `It's draw!`;
    }else if(x>y){
        return `${nameX} won (${x} vs. ${y})`;
    }else{
        return `${nameY} won (${y} vs. ${x})`;
    }
}

console.log(checkWinner(dolphinsAvarage, 'Dolphins', koalasAvarage, 'Koalas'))
*/


const friend1 = "Micheal";
const friend2 = "Steven";
const friend3 = "Peter";

const friends = ['Micheal', 'Steven', 'Peter'];
console.log(friends);

const y = new Array(1991, 1984, 2008, 2020);

console.log(friends[0]);
console.log(friends[2]);

console.log(friends.length);
console.log(friends[friends.length - 1]);

friends[2] = 'Jay';
console.log(friends);

const firstName = 'Jonas';
const jonas = [firstName, 'Schmedtmann', 2037 - 1991, 'teacher',friends];
console.log(jonas);
console.log(jonas.length);

//Exercise
const calcAge = function (birthYear){
    return 2037 - birthYear;
}
const years = [1991, 1967, 2002, 2010, 2018];

const age1 = calcAge(years[0]);
const age2 = calcAge(years[1]);
const age3 = calcAge(years[years.length - 1]);

console.log(age1, age2, age3);

const ages = [calcAge(years[0]), calcAge(years[1]), calcAge(years[years.length-1])];
console.log(ages);
