/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    memory = {}
    return function(...args) {
        if (memory[args] === undefined) {
            memory[args] = fn(...args);
        }
        return memory[args];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
