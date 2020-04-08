// Source : https://leetcode-cn.com/problems/unique-morse-code-words/
// Author : Lianfeng Shen
// Date   : 2020-04-09

func uniqueMorseRepresentations(words []string) int {
    var (
        d      = map[string]bool{}
        morses = []string{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}
    )
    for _, word := range words {
        tmpS := ""
        for _, ch := range word {
            tmpS += morses[ch-'a']
        }
        d[tmpS] = true
    }
    return len(d)
}