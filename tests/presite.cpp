#include"../binder.con"
int main(){
int number=Math.random();while(true){int guess=console.in("Your guess :");if(number==guess){console.log("You win\n");break;}else if(number>guess){console.log("Guess a higher number");}else if(number<guess){console.log("Guess a lower number");}else{console.log("You lose try again\n");}}}
