/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let current = n; // Initialize with the starting value n
    
    return function() {
        return current++; // Return the current value, then increment by 1
    };
};
/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */