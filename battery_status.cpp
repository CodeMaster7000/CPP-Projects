#define PATH_BATT_CHARGE_NOW "/sys/class/power_supply/BAT0/subsystem/BAT0/charge_now"
#define PATH_BATT_CHARGE_FULL "/sys/class/power_supply/BAT0/subsystem/BAT0/charge_full"
int getBattState(void)
    {
        int chargedPercent = 0;
        FILE *battChargeNow;
        FILE *battChargeFull;
        long unsigned int battMax_mAh = 0;
        long unsigned int battRemain_mAh = 0;
        if (NULL == (battChargeNow = fopen(PATH_BATT_CHARGE_NOW, "r")))
        {
            fclose(battChargeNow);
            return -1;
        }
        if (NULL == (battChargeFull = fopen(PATH_BATT_CHARGE_FULL, "r")))
        {
            fclose(battChargeNow);
            fclose(battChargeFull);
            return -1;
        }
        fscanf((FILE *)battChargeFull, "%lu", &battMax_mAh);
        fscanf((FILE *)battChargeNow, "%lu", &battRemain_mAh);
        chargedPercent = 100.00 * ((float)battRemain_mAh / (float)battMax_mAh);
        return chargedPercent;
    }
