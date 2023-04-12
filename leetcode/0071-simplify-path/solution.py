class Solution:
    def simplifyPath(self, path: str) -> str:
        my_path = []
        for p in path.split('/'):
            if p == '' or p == '.':
                continue
            elif p == '..':
                my_path = my_path[:-1]
            else:
                my_path.append(p)

        return '/' + '/'.join(my_path)
