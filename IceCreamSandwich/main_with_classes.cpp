#include <iostream>
using namespace std;


class IceCreamSandwich 
{
private:
    string value;
public:
    IceCreamSandwich(string _value) 
    {
        value = _value;
    }

    /**
     * @brief Are all characters are the same in middle in a string?
     * 
     * @param middle The string obtained from the slice
     * @return true All characters are the same in middle in a string
     * @return false Not all characters are the same in middle in a string
     */
    bool areAllCharsSameInMiddle(string middle) {
        if (middle.length() == 0) {
            return true;
        }
        char firstChar = middle[0];
        for (unsigned i = 1; i < middle.length(); i++) {
            if (middle[i] != firstChar) {
                return false;
            }
        }
        return true;
    }


    /**
     * @brief Get an number of matches that is equal to the previous one to get the beginning of the string
     * 
     * @param value Full string
     * @param strOfStart String to compare with the previous character
     * @param indexOfStart Number of matches with previous characters
     * @return int Number of matches with previous characters
     */
    int getIndexOfStart(string strOfStart, int indexOfStart) {
        for (unsigned i = 0; i <= value.length() - 1; i++) {
            strOfStart += value[i];
            if (strOfStart[strOfStart.length() - 1] == value[i + 1]) {
                indexOfStart += 1;
            }
            else {
                break;
            }
            
        }
        return indexOfStart;
    }


    /**
     * @brief Get an number of matches that is equal to the following to get the end of the string
     * 
     * @param value Full string
     * @param strOfEnd String to compare with the following character
     * @param indexOfEnd Number of matches with following characters
     * @return int Number of matches with following characters
     */
    int getIndexOfEnd(string strOfEnd, int indexOfEnd) {
        for (int i = value.length() - 1; i >= 0; i--) {
            strOfEnd += value[i];
            if (strOfEnd[strOfEnd.length() - 1] == value[i - 1]) {
                indexOfEnd += 1;
            }
            else {
                break;
            }
        }
        return indexOfEnd;
    }


    /**
     * @brief Are all characters are the same in a string?
     * 
     * @param value Full string
     * @return true All characters are the same in a string
     * @return false Not all characters are the same in a string
     */
    bool areAllCharsSame() {
        if (value.length() < 3) {
            return false;
        }
        
        int indexOfStart = 0;
        string strOfStart = "";

        int indexOfEnd = 0;
        string strOfEnd = "";

        if (value[value.length() - 1] == value[0]) {
            indexOfStart += 1;
            indexOfEnd += 1;
        }

        indexOfStart = getIndexOfStart(strOfStart, indexOfStart);
        indexOfEnd = getIndexOfEnd(strOfEnd, indexOfEnd);

        if (indexOfStart == indexOfEnd) {
            return areAllCharsSameInMiddle(value.substr(indexOfStart, value.length() - indexOfStart - indexOfEnd));
        }
        return false;
    }

};


/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    IceCreamSandwich iceCreamSandwich("hhmmhh");
    cout << boolalpha << iceCreamSandwich.areAllCharsSame() << endl;
    return 0;
}