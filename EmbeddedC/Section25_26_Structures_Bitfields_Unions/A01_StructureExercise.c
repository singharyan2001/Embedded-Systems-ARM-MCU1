/*
    Author: Aryan Singh
    Topic: Structures
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

struct Packet{
    uint8_t crc;        //2 bits
    uint8_t status;     //1 bit
    uint16_t Payload;   //12 bits
    uint8_t bat;        //3 bits
    uint8_t sensor;     //3 bits
    uint8_t long_addr;  //8 bits
    uint8_t short_addr; //2 bits
    uint8_t addr_mode;  //1 bit
};

int main()
{
    uint32_t packetvalue;
    printf("Enter the 32bit packet value in hex format:");
    scanf("%X", &packetvalue);

    struct Packet packet;

    packet.crc = (uint8_t) (packetvalue & 0x03);
    /*
    packet.status =(uint8_t) (packetvalue & 0x04);
    packet.Payload = (uint16_t) (packetvalue & 0x0FF4);
    */
    packet.status       = (uint8_t) ((packetvalue >> 2) & 0x01);
    packet.Payload      = (uint16_t) ((packetvalue >> 3) & 0x0FFF);
    packet.bat          = (uint8_t) ((packetvalue >> 15) & 0x07);
    packet.sensor       = (uint8_t) ((packetvalue >> 18) & 0x07);
    packet.long_addr    = (uint8_t) ((packetvalue >> 21) & 0xFF);
    packet.short_addr   = (uint8_t) ((packetvalue >> 29) & 0x03);
    packet.addr_mode    = (uint8_t) ((packetvalue >> 31) & 0x01);

    printf("CRC: 0x%X\n", packet.crc);
    printf("Status: 0x%X\n", packet.status);
    printf("Payload: 0x%X\n", packet.Payload);
    printf("BAT: 0x%X\n", packet.bat);
    printf("Sensor: 0x%X\n", packet.sensor);
    printf("Long_ADDR: 0x%X\n", packet.long_addr);
    printf("Short_ADDR: 0x%X\n", packet.short_addr);
    printf("ADDR_MODE: 0x%X\n", packet.addr_mode);

    uint32_t Size = sizeof(packet);
    printf("Size of Structure Packet is: %d\n", Size);

    return 0;
}
