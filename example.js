let number : int  = Math.random();
while(true){
    let guess : int = console.in("Your guess :");
    if(number == guess){
        console.log("You win\n");
        break;
    }else if(number > guess){
        console.log("Guess a higher number\n");
    }else if(number < guess){
        console.log("Guess a lower number\n");
    }
    else{
        console.log("You lose try again\n");
    }
}