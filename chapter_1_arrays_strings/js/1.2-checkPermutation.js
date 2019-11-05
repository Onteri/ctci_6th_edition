/* O(nlog(n)) solution due to initial sort */

/* Sorts string */
const sorted = str =>
  str
    .split("")
    .sort()
    .join("")

/* Determines if two strings are permutations of
   each other. */
const checkPermutationSort = (string1, string2) => {
  if (string1.length != string2.length) return false
  return sorted(string1) === sorted(string2)
}

/* O(n) solution */

/* Creates hash table of string */
const createMap = str => {
  return str.split("").reduce((a, b) => {
    a[b] ? a[b]++ : (a[b] = 1)
    return a
  }, {})
}

/* Determines if two strings are permutations of
   each other. */
const checkPermutation = (string1, string2) => {
  if (string1.length != string2.length) return false
  const map = createMap(string1)
  for (let ch of string2) {
    if (!map[ch]) return false
    map[ch]--
    /* if array map has a negative value, there is
       a mismatch in characters */
    if (map[ch] < 0) return false
  }
  return true
}

console.log(checkPermutation("dog", "god")) // true
console.log(checkPermutation("dog", "God")) // false
console.log(checkPermutation("dog", "good")) // false
console.log(checkPermutation("mmmmm", "mmmmm")) // true
console.log(checkPermutation("mmmmm", "mmmmn")) // false
