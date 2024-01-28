/*
    Author: Aryan Singh
    Topic: Union Applicabilty - bit extraction and storing mutually exclusive data thus saving memory.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

union Packet{
    uint32_t packetValue;   //4 Bytes
    struct                  //4 Bytes
    {
        uint32_t crc:2;        //2 bits
        uint32_t status:1;     //1 bit
        uint32_t Payload:12;   //12 bits
        uint32_t bat:3;        //3 bits
        uint32_t sensor:3;     //3 bits
        uint32_t long_addr:8;  //8 bits
        uint32_t short_addr:2; //2 bits
        uint32_t addr_mode:1;  //1 bit
    }packetfields; 
};


int main()
{
    union Packet packet;
    printf("Enter the 32bit packet value in hex format:");
    scanf("%X", &packet.packetValue);
/*
    struct Packet packet;

    packet.status       = (uint8_t) ((packetvalue >> 2) & 0x01);
    packet.Payload      = (uint16_t) ((packetvalue >> 3) & 0x0FFF);
    packet.bat          = (uint8_t) ((packetvalue >> 15) & 0x07);
    packet.sensor       = (uint8_t) ((packetvalue >> 18) & 0x07);
    packet.long_addr    = (uint8_t) ((packetvalue >> 21) & 0xFF);
    packet.short_addr   = (uint8_t) ((packetvalue >> 29) & 0x03);
    packet.addr_mode    = (uint8_t) ((packetvalue >> 31) & 0x01);
    //There is method to skip the above code. (for extracting data)
    //The technique is to use the combination of union and a struct.
*/
    printf("CRC: 0x%X\n", packet.packetfields.crc);
    printf("Status: 0x%X\n", packet.packetfields.status);
    printf("Payload: 0x%X\n", packet.packetfields.Payload);
    printf("BAT: 0x%X\n", packet.packetfields.bat);
    printf("Sensor: 0x%X\n", packet.packetfields.sensor);
    printf("Long_ADDR: 0x%X\n", packet.packetfields.long_addr);
    printf("Short_ADDR: 0x%X\n", packet.packetfields.short_addr);
    printf("ADDR_MODE: 0x%X\n", packet.packetfields.addr_mode);

    printf("Size of union is %I64u\n", sizeof(packet));

    while(getchar() != '\n'){
        getchar();
    }

    return 0;
}