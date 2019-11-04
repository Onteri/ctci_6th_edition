const isAlpha = ch => {
  // case insensitive regex
  return /^[A-Z]$/i.test(ch)
}

// O(n) solution
const isPaliPermutation = str => {
  const obj = {}
  let odds = 0
  for (let ch of str) {
    if (isAlpha(ch)) {
      obj[ch] == undefined ? (obj[ch] = 1) : obj[ch]++
      obj[ch] % 2 != 0 ? odds++ : odds--
    }
  }
  return odds <= 1
}

console.log(isPaliPermutation("tact coa")) // true
console.log(isPaliPermutation("tact coao")) // true
console.log(isPaliPermutation("tact ccoa")) // false
console.log(isPaliPermutation("tact coaz")) // false
console.log(isPaliPermutation("at ta")) // true
console.log(isPaliPermutation("t")) // true
