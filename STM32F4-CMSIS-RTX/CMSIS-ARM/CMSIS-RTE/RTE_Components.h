
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'F417ZGT6_RTE' 
 * Target:  'Target 1' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "stm32f4xx.h"

/* ARM::CMSIS:RTOS2:Keil RTX5&Source@5.9.0 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
        #define RTE_CMSIS_RTOS2_RTX5_SOURCE     /* CMSIS-RTOS2 Keil RTX5 Source */

/* ARM::CMSIS-View:Event Recorder&DAP@1.6.0 */
#define RTE_CMSIS_View_EventRecorder
        #define RTE_CMSIS_View_EventRecorder_DAP

/* ARM::CMSIS-Compiler:STDERR:Event Recorder@1.1.0 */
// #define RTE_CMSIS_Compiler_STDERR                /* CMSIS-Compiler STDERR */
        // #define RTE_CMSIS_Compiler_STDERR_Event_Recorder /* CMSIS-Compiler STDERR: Event Recorder */
        // #define RTE_CMSIS_Compiler_STDERR_Custom         /* CMSIS-Compiler STDERR: Custom */

/* ARM::CMSIS-Compiler:STDIN:Custom@1.1.0 */
// #define RTE_CMSIS_Compiler_STDIN                 /* CMSIS-Compiler STDIN */
        // #define RTE_CMSIS_Compiler_STDIN_Custom          /* CMSIS-Compiler STDIN: Custom */
		
/* ARM::CMSIS-Compiler:STDOUT:Event Recorder@1.1.0 */
// #define RTE_CMSIS_Compiler_STDOUT                /* CMSIS-Compiler STDOUT */
        // #define RTE_CMSIS_Compiler_STDOUT_Event_Recorder /* CMSIS-Compiler STDOUT: Event Recorder */
		// #define RTE_CMSIS_Compiler_STDOUT_Custom         /* CMSIS-Compiler STDOUT: Custom */

/* Keil::CMSIS-Compiler:File Interface:MDK-MW File System@1.0.0 */
// #define RTE_CMSIS_Compiler_File_Interface        /* CMSIS-Compiler File Interface */
        // #define RTE_CMSIS_Compiler_File_Interface_MDK_MW /* CMSIS-Compiler File Interface: MDK-Middleware File System */

/* Keil::CMSIS Driver:Ethernet:RNDIS@1.2.0 */
// #define RTE_Drivers_ETH_CDC_ACM_RNDIS   /* Driver ETH CDC ACM RNDIS */

/* Keil::CMSIS Driver:USB Device:Full-speed@2.23 */
// #define RTE_Drivers_USBD0               /* Driver USBD0 */

/* Keil::File System&MDK-Pro:CORE&LFN Debug@6.16.6 */
/* Keil::File System&MDK-Pro:CORE&LFN Release@6.16.6 */
// #define RTE_FileSystem_Core             /* File System Core */
          // #define RTE_FileSystem_LFN              /* File System with Long Filename support */
		  // #define RTE_FileSystem_SFN              /* File System without Long Filename support */
		  // #define RTE_FileSystem_Debug            /* File System Debug Version */
		  // #define RTE_FileSystem_Release          /* File System Release Version */

/* Keil::File System&MDK-Pro:Drive:Memory Card@6.16.6 */
// #define RTE_FileSystem_Drive_MC_0       /* File System Memory Card Drive 0 */

/* Keil::File System&MDK-Pro:Drive:NAND@6.16.6 */
// #define RTE_FileSystem_Drive_NAND_0     /* File System NAND Flash Drive 0 */

/* Keil::File System&MDK-Pro:Drive:NOR@6.16.6 */
// #define RTE_FileSystem_Drive_NOR_0      /* File System NOR Flash Drive 0 */

/* Keil::File System&MDK-Pro:Drive:RAM@6.16.6 */
// #define RTE_FileSystem_Drive_RAM_0      /* File System RAM Drive 0 */

/* Keil::File System&MDK-Pro:Drive:USB@6.16.6 */
// #define RTE_FileSystem_Drive_USB_0      /* File System USB Drive 0 */

/* Keil::Network&MDK-Pro:CORE&IPv4 Debug@7.19.0 */
/* Keil::Network&MDK-Pro:CORE&IPv4 Release@7.19.0 */
// #define RTE_Network_Core                /* Network Core */
          // #define RTE_Network_IPv4                /* Network IPv4 Stack */
		  // #define RTE_Network_IPv6                /* Network IPv6 Stack */
          // #define RTE_Network_Debug               /* Network Debug Version */
		  // #define RTE_Network_Debug_STDIO         /* Network Debug STDIO Version */
		  // #define RTE_Network_Release             /* Network Release Version */

/* Keil::Network&MDK-Pro:Interface:ETH@7.19.0 */
// #define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */

/* Keil::Network&MDK-Pro:Legacy API@7.19.0 */
// #define RTE_Network_Legacy              /* Network Legacy */

/* Keil::Network&MDK-Pro:Service:DNS Client@7.19.0 */
// #define RTE_Network_DNS_Client          /* Network DNS Client */

/* Keil::Network&MDK-Pro:Service:FTP Client@7.19.0 */
// #define RTE_Network_FTP_Client          /* Network FTP Client */

/* Keil::Network&MDK-Pro:Service:FTP Server@7.19.0 */
// #define RTE_Network_FTP_Server          /* Network FTP Server */

/* Keil::Network&MDK-Pro:Service:SMTP Client&SMTP@7.19.0 */
// #define RTE_Network_SMTP_Client         /* Network SMTP Client */

/* Keil::Network&MDK-Pro:Service:SNMP Agent@7.19.0 */
// #define RTE_Network_SNMP_Agent          /* Network SNMP Agent */

/* Keil::Network&MDK-Pro:Service:SNTP Client@7.19.0 */
// #define RTE_Network_SNTP_Client         /* Network SNTP Client */

/* Keil::Network&MDK-Pro:Service:TFTP Client@7.19.0 */
// #define RTE_Network_TFTP_Client         /* Network TFTP Client */

/* Keil::Network&MDK-Pro:Service:TFTP Server@7.19.0 */
// #define RTE_Network_TFTP_Server         /* Network TFTP Server */

/* Keil::Network&MDK-Pro:Service:Telnet Server@7.19.0 */
// #define RTE_Network_Telnet_Server       /* Network Telnet Server */

/* Keil::Network&MDK-Pro:Service:Web Server Compact&HTTP@7.19.0 */
// #define RTE_Network_Web_Server_RO       /* Network Web Server with Read-only Web Resources */

/* Keil::Network&MDK-Pro:Service:Web Server&HTTP@7.19.0 */
// #define RTE_Network_Web_Server_FS       /* Network Web Server with Web Resources on File System */

/* Keil::Network&MDK-Pro:Socket:BSD@7.19.0 */
// #define RTE_Network_Socket_BSD          /* Network Socket BSD */

/* Keil::Network&MDK-Pro:Socket:TCP@7.19.0 */
// #define RTE_Network_Socket_TCP          /* Network Socket TCP */

/* Keil::Network&MDK-Pro:Socket:UDP@7.19.0 */
// #define RTE_Network_Socket_UDP          /* Network Socket UDP */

/* Keil::USB&MDK-Pro:CORE&Debug@6.17.0 */
/* Keil::USB&MDK-Pro:CORE&Release@6.17.0 */
// #define RTE_USB_Core                    /* USB Core */
          // #define RTE_USB_Core_Debug              /* USB Core Debug Version */
		  // #define RTE_USB_Core_Release            /* USB Core Release Version */

/* Keil::USB&MDK-Pro:Device:ADC@6.17.0 */
// #define RTE_USB_Device_ADC_0            /* USB Device ADC instance 0 */

/* Keil::USB&MDK-Pro:Device:CDC@6.17.0 */
// #define RTE_USB_Device_CDC_0            /* USB Device CDC instance 0 */

/* Keil::USB&MDK-Pro:Device:Custom Class@6.17.0 */
// #define RTE_USB_Device_CustomClass_0    /* USB Device Custom Class instance 0 */

/* Keil::USB&MDK-Pro:Device:HID@6.17.0 */
// #define RTE_USB_Device_HID_0            /* USB Device HID instance 0 */

/* Keil::USB&MDK-Pro:Device:MSC@6.17.0 */
// #define RTE_USB_Device_MSC_0            /* USB Device MSC instance 0 */

/* Keil::USB&MDK-Pro:Device@6.17.0 */
// #define RTE_USB_Device_0                /* USB Device 0 */

/* Segger::Graphics&MDK-Pro:CORE@6.32.3 */
// #define RTE_Graphics_Core               /* Graphics Core */

/* Keil::Device:STM32Cube Framework:Classic@1.8.1 */
// #define RTE_DEVICE_FRAMEWORK_CLASSIC


#endif /* RTE_COMPONENTS_H */
