class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {

        int num1 = 0, num2 = 0, num3 = 0;

        for (int i = 0; i < firstWord.length(); i++)
        {
            num1 = num1 * 10 + (firstWord[i] - 'a');
        }

        for (int i = 0; i < secondWord.length(); i++)
        {
            num2 = num2 * 10 + (secondWord[i] - 'a');
        }

        for (int i = 0; i < targetWord.length(); i++) 
        {
            num3 = num3 * 10 + (targetWord[i] - 'a');
        }
        int res = num1 + num2;
        if (res == num3)
            return true;

        return false;
    }
};