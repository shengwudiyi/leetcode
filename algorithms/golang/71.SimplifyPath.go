// Source : https://leetcode-cn.com/problems/simplify-path/
// Author : Lianfeng Shen
// Date   : 2019-05-15

func simplifyPath(path string) string {
	stack := []string{}

	for _, sub := range strings.Split(path, "/") {
		if sub == ".." {
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		} else if sub != "." && sub != "" {
			stack = append(stack, sub)
		} else {
			continue
		}
	}

	return "/" + strings.Join(stack, "/")
}
