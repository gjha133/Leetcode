/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    let ans = []
    for(let i = 1; i <= n; i++) {
        let string = ''
        if(i % 3 == 0) string += 'Fizz'
        if(i % 5 == 0) string += 'Buzz'
        
        if(string === '') string += i
        ans.push(string)
    }
    
    return ans;
};