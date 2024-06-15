char* __color(int __x)
{
    switch (__x)
    {
    case 0:
        return "\033[0m"; //Reset
        break;

    case 1:
        return "\033[0;31m"; //Red
        break;

    case 2:
        return "\033[0;32m"; //Green
        break;

    case 3:
        return "\033[0;33m"; // Yellow
        break;

    case 4:
        return "\033[0;34m"; // Blue
        break;
    
    case 5:
        return "\033[0;36m"; // Cyan
        break;

    default:
        return "";
    }
}