/**
 * Determines whether specified node is engineer or doctor
 * @level: Level in tree node is in
 * @pos: Position specified level
 *
 * Return: String "Engineer" if node is engineer, otherwise "Doctor"
 */
char *find_profession(int level, int pos)
{
	if (level == 1)
                return ("Engineer");
        if (find_profession(level - 1, (pos + 1) / 2) == "Doctor")
                return (pos % 2 ? "Doctor" : "Engineer");
        return (pos % 2 ? "Engineer" : "Doctor");
}
