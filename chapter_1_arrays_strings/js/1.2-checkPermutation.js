// O(n) solution

const createMap = str => {
  return str.split("").reduce((a, b) => {
    a[b] ? a[b]++ : (a[b] = 1)
    return a
  }, {})
}

const checkPermutation = (string1, string2) => {
  if (string1.length != string2.length) return false
  const map = createMap(string1)
  for (let ch of string2) {
    if (!map[ch]) return false
    map[ch]--
    if (map[ch] < 0) return false
  }
  return true
}

console.log(checkPermutation("dog", "god")) // true
console.log(checkPermutation("dog", "God")) // false
console.log(checkPermutation("dog", "good")) // false
console.log(checkPermutation("mmmmm", "mmmmm")) // true
console.log(checkPermutation("mmmmm", "mmmmn")) // false
