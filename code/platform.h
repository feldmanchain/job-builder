struct platform_vbox_client
{
    IVirtualBoxClient *Client;
    IVirtualBox *VBox;
};

// TODO(Oskar): This is not a true platform layer as the return types doesn't match with xpcom
// we will fix this in the future.
struct platform
{
    platform_vbox_client (*InitVirtualBox)(void);
    void (*ListVirtualMachines)(IVirtualBox*);
};