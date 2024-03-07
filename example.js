while(true){
    let guess : int = console.in("Your guess :");
    let number : int  = 11;
    if(number == guess){
        console.log("You win\n");
        break;
    }
    else{
        console.log("You lose try again\n");
    }
}