3	0.0000000	fa:dd:d0:4c:e5:2e	CloudNetwork_e3:df:3b	EAPOL	163	Key (Message 1 of 4)
```
Frame 3: Packet, 163 bytes on wire (1304 bits), 163 bytes captured (1304 bits)
    Encapsulation type: IEEE 802.11 plus Network Monitor radio header (126)
    Arrival Time: Apr  1, 2026 14:53:08.605049400 中国标准时间
    UTC Arrival Time: Apr  1, 2026 06:53:08.605049400 UTC
    Epoch Arrival Time: 1775026388.605049400
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.000000000 seconds]
    [Time since reference or first frame: 0.000000000 seconds]
    Frame Number: 3
    Frame Length: 163 bytes (1304 bits)
    Capture Length: 163 bytes (1304 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: netmon_802_11:wlan_radio:wlan:llc:eapol]
    Character encoding: ASCII (0)
NetMon 802.11 capture header
    Header revision: 2
    Header length: 32
    Operation mode: 0x00000004
        .... .... .... .... .... .... .... ...0 = Station mode: 0x0
        .... .... .... .... .... .... .... ..0. = AP mode: 0x0
        .... .... .... .... .... .... .... .1.. = Extensible station mode: 0x1
        0... .... .... .... .... .... .... .... = Monitor mode: 0x0
    PHY type: Unknown (0)
    Center frequency: 2437MHz
    RSSI: Unknown
    Data rate: Unknown
    Timestamp: 134194999886050494
802.11 radio information
    Channel: 6
    Frequency: 2437MHz
    TSF timestamp: 134194999886050494
IEEE 802.11 Data, Flags: ......F.
    Type/Subtype: Data (0x0020)
    Frame Control Field: 0x0802
        .... ..00 = Version: 0
        .... 10.. = Type: Data frame (2)
        0000 .... = Subtype: 0
        Flags: 0x02
            .... ..10 = DS status: Frame from DS to a STA via AP(To DS: 0 From DS: 1) (0x2)
            .... .0.. = More Fragments: This is the last fragment
            .... 0... = Retry: Frame is not being retransmitted
            ...0 .... = PWR MGT: STA will stay up
            ..0. .... = More Data: No data buffered
            .0.. .... = Protected flag: Data is not protected
            0... .... = +HTC/Order flag: Not strictly ordered
    .000 0001 0011 1010 = Duration: 314 microseconds
    Receiver address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Transmitter address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Destination address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    BSS Id: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    STA address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    .... .... .... 0000 = Fragment number: 0
    0000 0000 0000 .... = Sequence number: 0
    [WLAN Flags: ......F.]
Logical-Link Control
    DSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = IG Bit: Individual
    SSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = CR Bit: Command
    Control field: U, func=UI (0x03)
        000. 00.. = Command: Unnumbered Information (0x00)
        .... ..11 = Frame type: Unnumbered frame (0x3)
    Organization Code: 00:00:00 (Officially Xerox, but 0:0:0:0:0:0 is more common)
    Type: 802.1X Authentication (0x888e)
802.1X Authentication
    Version: 802.1X-2004 (2)
    Type: Key (3)
    Length: 95
    Key Descriptor Type: EAPOL RSN Key (2)
    [Message number: 1]
    Key Information: 0x008a
        .... .... .... .010 = Key Descriptor Version: AES Cipher, HMAC-SHA1 MIC (2)
        .... .... .... 1... = Key Type: Pairwise Key
        .... .... ..00 .... = Key Index: 0
        .... .... .0.. .... = Install: Not set
        .... .... 1... .... = Key ACK: Set
        .... ...0 .... .... = Key MIC: Not set
        .... ..0. .... .... = Secure: Not set
        .... .0.. .... .... = Error: Not set
        .... 0... .... .... = Request: Not set
        ...0 .... .... .... = Encrypted Key Data: Not set
        ..0. .... .... .... = SMK Message: Not set
    Key Length: 16
    Replay Counter: 1
    WPA Key Nonce: 216bfc0c4b63d21060871df4ba7d27a694f62ac74d0314887c462d5cff9f2f23
    Key IV: 00000000000000000000000000000000
    WPA Key RSC: 0000000000000000
    WPA Key ID: 0000000000000000
    WPA Key MIC: 00000000000000000000000000000000
    WPA Key Data Length: 0

```

4	0.0000486	CloudNetwork_e3:df:3b	fa:dd:d0:4c:e5:2e	EAPOL	187	Key (Message 2 of 4)
```
Frame 4: Packet, 187 bytes on wire (1496 bits), 187 bytes captured (1496 bits)
    Encapsulation type: IEEE 802.11 plus Network Monitor radio header (126)
    Arrival Time: Apr  1, 2026 14:53:08.605098000 中国标准时间
    UTC Arrival Time: Apr  1, 2026 06:53:08.605098000 UTC
    Epoch Arrival Time: 1775026388.605098000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 48.600 microseconds]
    [Time delta from previous displayed frame: 48.600 microseconds]
    [Time since reference or first frame: 48.600 microseconds]
    Frame Number: 4
    Frame Length: 187 bytes (1496 bits)
    Capture Length: 187 bytes (1496 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: netmon_802_11:wlan_radio:wlan:llc:eapol]
    Character encoding: ASCII (0)
NetMon 802.11 capture header
    Header revision: 2
    Header length: 32
    Operation mode: 0x00000004
        .... .... .... .... .... .... .... ...0 = Station mode: 0x0
        .... .... .... .... .... .... .... ..0. = AP mode: 0x0
        .... .... .... .... .... .... .... .1.. = Extensible station mode: 0x1
        0... .... .... .... .... .... .... .... = Monitor mode: 0x0
    Timestamp: 134194999886050980
802.11 radio information
    TSF timestamp: 134194999886050980
IEEE 802.11 Data, Flags: .......T
    Type/Subtype: Data (0x0020)
    Frame Control Field: 0x0801
        .... ..00 = Version: 0
        .... 10.. = Type: Data frame (2)
        0000 .... = Subtype: 0
        Flags: 0x01
            .... ..01 = DS status: Frame from STA to DS via an AP (To DS: 1 From DS: 0) (0x1)
            .... .0.. = More Fragments: This is the last fragment
            .... 0... = Retry: Frame is not being retransmitted
            ...0 .... = PWR MGT: STA will stay up
            ..0. .... = More Data: No data buffered
            .0.. .... = Protected flag: Data is not protected
            0... .... = +HTC/Order flag: Not strictly ordered
    .000 0000 0000 0000 = Duration: 0 microseconds
    Receiver address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Transmitter address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Destination address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    BSS Id: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    STA address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    .... .... .... 0000 = Fragment number: 0
    0000 0000 0000 .... = Sequence number: 0
    [WLAN Flags: .......T]
Logical-Link Control
    DSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = IG Bit: Individual
    SSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = CR Bit: Command
    Control field: U, func=UI (0x03)
        000. 00.. = Command: Unnumbered Information (0x00)
        .... ..11 = Frame type: Unnumbered frame (0x3)
    Organization Code: 00:00:00 (Officially Xerox, but 0:0:0:0:0:0 is more common)
    Type: 802.1X Authentication (0x888e)
802.1X Authentication
    Version: 802.1X-2001 (1)
    Type: Key (3)
    Length: 119
    Key Descriptor Type: EAPOL RSN Key (2)
    [Message number: 2]
    Key Information: 0x010a
        .... .... .... .010 = Key Descriptor Version: AES Cipher, HMAC-SHA1 MIC (2)
        .... .... .... 1... = Key Type: Pairwise Key
        .... .... ..00 .... = Key Index: 0
        .... .... .0.. .... = Install: Not set
        .... .... 0... .... = Key ACK: Not set
        .... ...1 .... .... = Key MIC: Set
        .... ..0. .... .... = Secure: Not set
        .... .0.. .... .... = Error: Not set
        .... 0... .... .... = Request: Not set
        ...0 .... .... .... = Encrypted Key Data: Not set
        ..0. .... .... .... = SMK Message: Not set
    Key Length: 0
    Replay Counter: 1
    WPA Key Nonce: f47887f78d799d5bc1dd7baff04ec01eb38e4dc788608b5ba41b9c8c50c4c797
    Key IV: 00000000000000000000000000000000
    WPA Key RSC: 0000000000000000
    WPA Key ID: 0000000000000000
    WPA Key MIC: b556814eaf60218091efbbbb1fce9936
    WPA Key Data Length: 24
    WPA Key Data: 30160100000fac040100000fac040100000fac0200000000
        Tag: RSN Information
            Tag Number: RSN Information (48)
            Tag length: 22
            RSN Version: 1
            Group Cipher Suite: 00:0f:ac (Ieee 802.11) AES (CCM)
                Group Cipher Suite OUI: 00:0f:ac (Ieee 802.11)
                Group Cipher Suite type: AES (CCM) (4)
            Pairwise Cipher Suite Count: 1
            Pairwise Cipher Suite List 00:0f:ac (Ieee 802.11) AES (CCM)
                Pairwise Cipher Suite: 00:0f:ac (Ieee 802.11) AES (CCM)
                    Pairwise Cipher Suite OUI: 00:0f:ac (Ieee 802.11)
                    Pairwise Cipher Suite type: AES (CCM) (4)
            Auth Key Management (AKM) Suite Count: 1
            Auth Key Management (AKM) List 00:0f:ac (Ieee 802.11) PSK
                Auth Key Management (AKM) Suite: 00:0f:ac (Ieee 802.11) PSK
                    Auth Key Management (AKM) OUI: 00:0f:ac (Ieee 802.11)
                    Auth Key Management (AKM) type: PSK (2)
            RSN Capabilities: 0x0000
                .... .... .... ...0 = RSN Pre-Auth capabilities: Transmitter does not support pre-authentication
                .... .... .... ..0. = RSN No Pairwise capabilities: Transmitter can support WEP default key 0 simultaneously with Pairwise key
                .... .... .... 00.. = RSN PTKSA Replay Counter capabilities: 1 replay counter per PTKSA/GTKSA/STAKeySA (0x0)
                .... .... ..00 .... = RSN GTKSA Replay Counter capabilities: 1 replay counter per PTKSA/GTKSA/STAKeySA (0x0)
                .... .... .0.. .... = Management Frame Protection Required: Not required
                .... .... 0... .... = Management Frame Protection Capable: Not capable
                .... ...0 .... .... = Joint Multi-band RSNA: Not supported
                .... ..0. .... .... = PeerKey Enabled: Not supported
                .... .0.. .... .... = SPP A-MSDU Capable: Not capable
                .... 0... .... .... = SPP A-MSDU Required: Not required
                ...0 .... .... .... = PBAC (protected block ack agreement capable): Not capable
                ..0. .... .... .... = Extended Key ID for Individually Addressed Frames: Not supported
                .0.. .... .... .... = OCVC: Not supported
            PMKID Count: 0
            PMKID List

```

5	0.0209926	fa:dd:d0:4c:e5:2e	CloudNetwork_e3:df:3b	EAPOL	219	Key (Message 3 of 4)
```
Frame 5: Packet, 219 bytes on wire (1752 bits), 219 bytes captured (1752 bits)
    Encapsulation type: IEEE 802.11 plus Network Monitor radio header (126)
    Arrival Time: Apr  1, 2026 14:53:08.626042000 中国标准时间
    UTC Arrival Time: Apr  1, 2026 06:53:08.626042000 UTC
    Epoch Arrival Time: 1775026388.626042000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 20.944000 milliseconds]
    [Time delta from previous displayed frame: 20.944000 milliseconds]
    [Time since reference or first frame: 20.992600 milliseconds]
    Frame Number: 5
    Frame Length: 219 bytes (1752 bits)
    Capture Length: 219 bytes (1752 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: netmon_802_11:wlan_radio:wlan:llc:eapol]
    Character encoding: ASCII (0)
NetMon 802.11 capture header
    Header revision: 2
    Header length: 32
    Operation mode: 0x00000004
        .... .... .... .... .... .... .... ...0 = Station mode: 0x0
        .... .... .... .... .... .... .... ..0. = AP mode: 0x0
        .... .... .... .... .... .... .... .1.. = Extensible station mode: 0x1
        0... .... .... .... .... .... .... .... = Monitor mode: 0x0
    PHY type: Unknown (0)
    Center frequency: 2437MHz
    RSSI: Unknown
    Data rate: Unknown
    Timestamp: 134194999886260420
802.11 radio information
    Channel: 6
    Frequency: 2437MHz
    TSF timestamp: 134194999886260420
IEEE 802.11 Data, Flags: ....R.F.
    Type/Subtype: Data (0x0020)
    Frame Control Field: 0x080a
        .... ..00 = Version: 0
        .... 10.. = Type: Data frame (2)
        0000 .... = Subtype: 0
        Flags: 0x0a
            .... ..10 = DS status: Frame from DS to a STA via AP(To DS: 0 From DS: 1) (0x2)
            .... .0.. = More Fragments: This is the last fragment
            .... 1... = Retry: Frame is being retransmitted
                [Expert Info (Note/Sequence): Retransmission (retry)]
                    [Retransmission (retry)]
                    [Severity level: Note]
                    [Group: Sequence]
            ...0 .... = PWR MGT: STA will stay up
            ..0. .... = More Data: No data buffered
            .0.. .... = Protected flag: Data is not protected
            0... .... = +HTC/Order flag: Not strictly ordered
    .000 0001 0011 1010 = Duration: 314 microseconds
    Receiver address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Transmitter address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Destination address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    BSS Id: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    STA address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    .... .... .... 0000 = Fragment number: 0
    0000 0000 0001 .... = Sequence number: 1
    [WLAN Flags: ....R.F.]
Logical-Link Control
    DSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = IG Bit: Individual
    SSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = CR Bit: Command
    Control field: U, func=UI (0x03)
        000. 00.. = Command: Unnumbered Information (0x00)
        .... ..11 = Frame type: Unnumbered frame (0x3)
    Organization Code: 00:00:00 (Officially Xerox, but 0:0:0:0:0:0 is more common)
    Type: 802.1X Authentication (0x888e)
802.1X Authentication
    Version: 802.1X-2004 (2)
    Type: Key (3)
    Length: 151
    Key Descriptor Type: EAPOL RSN Key (2)
    [Message number: 3]
    Key Information: 0x13ca
        .... .... .... .010 = Key Descriptor Version: AES Cipher, HMAC-SHA1 MIC (2)
        .... .... .... 1... = Key Type: Pairwise Key
        .... .... ..00 .... = Key Index: 0
        .... .... .1.. .... = Install: Set
        .... .... 1... .... = Key ACK: Set
        .... ...1 .... .... = Key MIC: Set
        .... ..1. .... .... = Secure: Set
        .... .0.. .... .... = Error: Not set
        .... 0... .... .... = Request: Not set
        ...1 .... .... .... = Encrypted Key Data: Set
        ..0. .... .... .... = SMK Message: Not set
    Key Length: 16
    Replay Counter: 2
    WPA Key Nonce: 216bfc0c4b63d21060871df4ba7d27a694f62ac74d0314887c462d5cff9f2f23
    Key IV: 00000000000000000000000000000000
    WPA Key RSC: 0000000000000000
    WPA Key ID: 0000000000000000
    WPA Key MIC: dceec1d909f4095bbbac1c5fe10bd53e
    WPA Key Data Length: 56
    WPA Key Data: e8c35de25a9e6eaef9eea7143d45d15bd5abdc9d8dc477b8fc87755f61fc3afc078d9337b3b131c561377a531890b584dc3ec87ae9e157fa

```

6	0.0210596	CloudNetwork_e3:df:3b	fa:dd:d0:4c:e5:2e	EAPOL	163	Key (Message 4 of 4)
```
Frame 6: Packet, 163 bytes on wire (1304 bits), 163 bytes captured (1304 bits)
    Encapsulation type: IEEE 802.11 plus Network Monitor radio header (126)
    Arrival Time: Apr  1, 2026 14:53:08.626109000 中国标准时间
    UTC Arrival Time: Apr  1, 2026 06:53:08.626109000 UTC
    Epoch Arrival Time: 1775026388.626109000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 67.000 microseconds]
    [Time delta from previous displayed frame: 67.000 microseconds]
    [Time since reference or first frame: 21.059600 milliseconds]
    Frame Number: 6
    Frame Length: 163 bytes (1304 bits)
    Capture Length: 163 bytes (1304 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: netmon_802_11:wlan_radio:wlan:llc:eapol]
    Character encoding: ASCII (0)
NetMon 802.11 capture header
    Header revision: 2
    Header length: 32
    Operation mode: 0x00000004
        .... .... .... .... .... .... .... ...0 = Station mode: 0x0
        .... .... .... .... .... .... .... ..0. = AP mode: 0x0
        .... .... .... .... .... .... .... .1.. = Extensible station mode: 0x1
        0... .... .... .... .... .... .... .... = Monitor mode: 0x0
    Timestamp: 134194999886261090
802.11 radio information
    TSF timestamp: 134194999886261090
IEEE 802.11 Data, Flags: .......T
    Type/Subtype: Data (0x0020)
    Frame Control Field: 0x0801
        .... ..00 = Version: 0
        .... 10.. = Type: Data frame (2)
        0000 .... = Subtype: 0
        Flags: 0x01
            .... ..01 = DS status: Frame from STA to DS via an AP (To DS: 1 From DS: 0) (0x1)
            .... .0.. = More Fragments: This is the last fragment
            .... 0... = Retry: Frame is not being retransmitted
            ...0 .... = PWR MGT: STA will stay up
            ..0. .... = More Data: No data buffered
            .0.. .... = Protected flag: Data is not protected
            0... .... = +HTC/Order flag: Not strictly ordered
    .000 0000 0000 0000 = Duration: 0 microseconds
    Receiver address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Transmitter address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Destination address: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    BSS Id: fa:dd:d0:4c:e5:2e (fa:dd:d0:4c:e5:2e)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    STA address: CloudNetwork_e3:df:3b (74:97:79:e3:df:3b)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    .... .... .... 0000 = Fragment number: 0
    0000 0000 0000 .... = Sequence number: 0
    [WLAN Flags: .......T]
Logical-Link Control
    DSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = IG Bit: Individual
    SSAP: SNAP (0xaa)
        1010 101. = SAP: SNAP
        .... ...0 = CR Bit: Command
    Control field: U, func=UI (0x03)
        000. 00.. = Command: Unnumbered Information (0x00)
        .... ..11 = Frame type: Unnumbered frame (0x3)
    Organization Code: 00:00:00 (Officially Xerox, but 0:0:0:0:0:0 is more common)
    Type: 802.1X Authentication (0x888e)
802.1X Authentication
    Version: 802.1X-2001 (1)
    Type: Key (3)
    Length: 95
    Key Descriptor Type: EAPOL RSN Key (2)
    [Message number: 4]
    Key Information: 0x030a
        .... .... .... .010 = Key Descriptor Version: AES Cipher, HMAC-SHA1 MIC (2)
        .... .... .... 1... = Key Type: Pairwise Key
        .... .... ..00 .... = Key Index: 0
        .... .... .0.. .... = Install: Not set
        .... .... 0... .... = Key ACK: Not set
        .... ...1 .... .... = Key MIC: Set
        .... ..1. .... .... = Secure: Set
        .... .0.. .... .... = Error: Not set
        .... 0... .... .... = Request: Not set
        ...0 .... .... .... = Encrypted Key Data: Not set
        ..0. .... .... .... = SMK Message: Not set
    Key Length: 0
    Replay Counter: 2
    WPA Key Nonce: 0000000000000000000000000000000000000000000000000000000000000000
    Key IV: 00000000000000000000000000000000
    WPA Key RSC: 0000000000000000
    WPA Key ID: 0000000000000000
    WPA Key MIC: ddffe6b10275306a40ac4bd2522527dd
    WPA Key Data Length: 0

```