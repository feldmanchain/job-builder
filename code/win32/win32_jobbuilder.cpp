STN_INTERNAL void 
Win32ListVirtualMachines(IVirtualBox *virtualBox)
{
    HRESULT rc;

    /*
     * First we have to get a list of all registered VMs
     */
    SAFEARRAY *machinesArray = NULL;

    printf("You Have the following VMs:\n");

    rc = virtualBox->get_Machines(&machinesArray);
    if (SUCCEEDED(rc))
    {
        IMachine **machines;
        rc = SafeArrayAccessData(machinesArray, (void **) &machines);
        if (SUCCEEDED(rc))
        {
            for (ULONG i = 0; i < machinesArray->rgsabound[0].cElements; ++i)
            {
                BSTR str;

                rc = machines[i]->get_Name(&str);
                if (SUCCEEDED(rc))
                {
                    printf("Name: %S\n", str);
                    SysFreeString(str);
                }
            }

            SafeArrayUnaccessData(machinesArray);
        }

        SafeArrayDestroy(machinesArray);
    }
}

STN_INTERNAL platform_vbox_client
Win32InitializeVirtualBox()
{
    platform_vbox_client Result = {};

    // IVirtualBoxClient *virtualBoxClient;
    HRESULT rc = CoCreateInstance(CLSID_VirtualBoxClient, /* the VirtualBoxClient object */
                                  NULL,                   /* no aggregation */
                                  CLSCTX_INPROC_SERVER,   /* the object lives in the current process */
                                  IID_IVirtualBoxClient,  /* IID of the interface */
                                  (void**)&Result.Client);
    if (SUCCEEDED(rc))
    {
        IVirtualBox *virtualBox;
        rc = Result.Client->get_VirtualBox(&Result.VBox);
        if (SUCCEEDED(rc))
        {
            printf("Successfully initialized VBox\n");
            // Win32ListVirtualMachines(virtualBox);

            /* Release the VirtualBox object. */
            // virtualBox->Release();
            // virtualBoxClient->Release();
        }
        else
        {
            printf("Error creating VirtualBox instance! rc = 0x%x\n", rc);
        }
    }
    else
    {
        printf("Error setting up COM rc = 0x%x\n", rc);
    }

    return (Result);
}