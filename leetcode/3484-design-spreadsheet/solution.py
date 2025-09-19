class Spreadsheet:

    def __init__(self, rows: int):
        self.map = {}

    def setCell(self, cell: str, value: int) -> None:
        self.map[cell] = value

    def resetCell(self, cell: str) -> None:
        self.map[cell] = 0

    def getValue(self, formula: str) -> int:
        a, b = formula[1:].split('+')
        a = int(a) if a.isdigit() else self.map.get(a, 0)
        b = int(b) if b.isdigit() else self.map.get(b, 0)
        return a + b


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
