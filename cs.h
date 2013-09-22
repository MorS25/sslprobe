#ifndef CS_H
#define CS_H

typedef enum {
	CLEAR,
	WEAK,
	MEDIUM,
	STRONG
} cipher_strength_t;

typedef struct {
	int id;
	int isCBC;
	cipher_strength_t strength;
	char *name;
} cipher_t;


/**
 * List based on data from TestSSLServer.java and IANA:
 * https://www.iana.org/assignments/tls-parameters/tls-parameters.xhtml
 */
static cipher_t ciphers[] = {
	/* SSLv2 */
	{ 0x010080,	0, STRONG,	"RC4_128_WITH_MD5" },
	{ 0x020080,	0, WEAK,	"RC4_128_EXPORT40_WITH_MD5" },
	{ 0x030080,	1, STRONG,	"RC2_128_CBC_WITH_MD5" },
	{ 0x040080,	1, WEAK,	"RC2_128_CBC_EXPORT40_WITH_MD5" },
	{ 0x050080,	1, STRONG,	"IDEA_128_CBC_WITH_MD5" },
	{ 0x060040,	1, MEDIUM,	"DES_64_CBC_WITH_MD5" },
	{ 0x0700C0,	1, STRONG,	"DES_192_EDE3_CBC_WITH_MD5" },

	/* SSLv3, TLS1.0 */
	{ 0x0000,	0, CLEAR,	"NULL_WITH_NULL_NULL" },
	{ 0x0001,	0, CLEAR,	"RSA_WITH_NULL_MD5" },
	{ 0x0002,	0, CLEAR,	"RSA_WITH_NULL_SHA" },
	{ 0x0003,	0, WEAK,	"RSA_EXPORT_WITH_RC4_40_MD5" },
	{ 0x0004,	0, STRONG,	"RSA_WITH_RC4_128_MD5" },
	{ 0x0005,	0, STRONG,	"RSA_WITH_RC4_128_SHA" },
	{ 0x0006,	1, WEAK,	"RSA_EXPORT_WITH_RC2_CBC_40_MD5" },
	{ 0x0007,	1, STRONG,	"RSA_WITH_IDEA_CBC_SHA" },
	{ 0x0008,	1, WEAK,	"RSA_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x0009,	1, MEDIUM,	"RSA_WITH_DES_CBC_SHA" },
	{ 0x000A,	1, STRONG,	"RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0x000B,	1, WEAK,	"DH_DSS_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x000C,	1, MEDIUM,	"DH_DSS_WITH_DES_CBC_SHA" },
	{ 0x000D,	1, STRONG,	"DH_DSS_WITH_3DES_EDE_CBC_SHA" },
	{ 0x000E,	1, WEAK,	"DH_RSA_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x000F,	1, MEDIUM,	"DH_RSA_WITH_DES_CBC_SHA" },
	{ 0x0010,	1, STRONG,	"DH_RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0011,	1, WEAK,	"DHE_DSS_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x0012,	1, MEDIUM,	"DHE_DSS_WITH_DES_CBC_SHA" },
	{ 0x0013,	1, STRONG,	"DHE_DSS_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0014,	1, WEAK,	"DHE_RSA_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x0015,	1, MEDIUM,	"DHE_RSA_WITH_DES_CBC_SHA" },
	{ 0x0016,	1, STRONG,	"DHE_RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0017,	0, WEAK,	"DH_anon_EXPORT_WITH_RC4_40_MD5" },
	{ 0x0018,	0, STRONG,	"DH_anon_WITH_RC4_128_MD5" },
	{ 0x0019,	1, WEAK,	"DH_anon_EXPORT_WITH_DES40_CBC_SHA" },
	{ 0x001A,	1, MEDIUM,	"DH_anon_WITH_DES_CBC_SHA" },
	{ 0x001B,	1, STRONG,	"DH_anon_WITH_3DES_EDE_CBC_SHA" },
	/* SSLv3 (RFC 6101) */
	{ 0x001C,	0, CLEAR,	"FORTEZZA_KEA_WITH_NULL_SHA" },
	{ 0x001D,	1, STRONG,	"FORTEZZA_KEA_WITH_FORTEZZA_CBC_SHA" },
	/*
	Conflict with Kerberos below
	{ 0x001E,	0, STRONG,	"FORTEZZA_KEA_WITH_RC4_128_SHA" },
	*/

	/* Kerberos (RFC 2712) */
	{ 0x001E,	1, MEDIUM,	"KRB5_WITH_DES_CBC_SHA" },
	{ 0x001F,	1, STRONG,	"KRB5_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0020,	0, STRONG,	"KRB5_WITH_RC4_128_SHA" },
	{ 0x0021,	1, STRONG,	"KRB5_WITH_IDEA_CBC_SHA" },
	{ 0x0022,	1, MEDIUM,	"KRB5_WITH_DES_CBC_MD5" },
	{ 0x0023,	1, STRONG,	"KRB5_WITH_3DES_EDE_CBC_MD5" },
	{ 0x0024,	0, STRONG,	"KRB5_WITH_RC4_128_MD5" },
	{ 0x0025,	1, STRONG,	"KRB5_WITH_IDEA_CBC_MD5" },
	{ 0x0026,	1, WEAK,	"KRB5_EXPORT_WITH_DES_CBC_40_SHA" },
	{ 0x0027,	1, WEAK,	"KRB5_EXPORT_WITH_RC2_CBC_40_SHA" },
	{ 0x0028,	0, WEAK,	"KRB5_EXPORT_WITH_RC4_40_SHA" },
	{ 0x0029,	1, WEAK,	"KRB5_EXPORT_WITH_DES_CBC_40_MD5" },
	{ 0x002A,	1, WEAK,	"KRB5_EXPORT_WITH_RC2_CBC_40_MD5" },
	{ 0x002B,	0, WEAK,	"KRB5_EXPORT_WITH_RC4_40_MD5" },

	/* Pre-shared key, NULL encryption (RFC 4785) */
	{ 0x002C,	0, CLEAR,	"PSK_WITH_NULL_SHA" },
	{ 0x002D,	0, CLEAR,	"DHE_PSK_WITH_NULL_SHA" },
	{ 0x002E,	0, CLEAR,	"RSA_PSK_WITH_NULL_SHA" },

	/* AES-based suites (TLS 1.1) */
	{ 0x002F,	1, STRONG,	"RSA_WITH_AES_128_CBC_SHA" },
	{ 0x0030,	1, STRONG,	"DH_DSS_WITH_AES_128_CBC_SHA" },
	{ 0x0031,	1, STRONG,	"DH_RSA_WITH_AES_128_CBC_SHA" },
	{ 0x0032,	1, STRONG,	"DHE_DSS_WITH_AES_128_CBC_SHA" },
	{ 0x0033,	1, STRONG,	"DHE_RSA_WITH_AES_128_CBC_SHA" },
	{ 0x0034,	1, STRONG,	"DH_anon_WITH_AES_128_CBC_SHA" },
	{ 0x0035,	1, STRONG,	"RSA_WITH_AES_256_CBC_SHA" },
	{ 0x0036,	1, STRONG,	"DH_DSS_WITH_AES_256_CBC_SHA" },
	{ 0x0037,	1, STRONG,	"DH_RSA_WITH_AES_256_CBC_SHA" },
	{ 0x0038,	1, STRONG,	"DHE_DSS_WITH_AES_256_CBC_SHA" },
	{ 0x0039,	1, STRONG,	"DHE_RSA_WITH_AES_256_CBC_SHA" },
	{ 0x003A,	1, STRONG,	"DH_anon_WITH_AES_256_CBC_SHA" },

	/* SHA256-based suites (TLS 1.2) */
	{ 0x003B,	0, CLEAR,	"RSA_WITH_NULL_SHA256" },
	{ 0x003C,	1, STRONG,	"RSA_WITH_AES_128_CBC_SHA256" },
	{ 0x003D,	1, STRONG,	"RSA_WITH_AES_256_CBC_SHA256" },
	{ 0x003E,	1, STRONG,	"DH_DSS_WITH_AES_128_CBC_SHA256" },
	{ 0x003F,	1, STRONG,	"DH_RSA_WITH_AES_128_CBC_SHA256" },
	{ 0x0040,	1, STRONG,	"DHE_DSS_WITH_AES_128_CBC_SHA256" },
	{ 0x0067,	1, STRONG,	"DHE_RSA_WITH_AES_128_CBC_SHA256" },
	{ 0x0068,	1, STRONG,	"DH_DSS_WITH_AES_256_CBC_SHA256" },
	{ 0x0069,	1, STRONG,	"DH_RSA_WITH_AES_256_CBC_SHA256" },
	{ 0x006A,	1, STRONG,	"DHE_DSS_WITH_AES_256_CBC_SHA256" },
	{ 0x006B,	1, STRONG,	"DHE_RSA_WITH_AES_256_CBC_SHA256" },
	{ 0x006C,	1, STRONG,	"DH_anon_WITH_AES_128_CBC_SHA256" },
	{ 0x006D,	1, STRONG,	"DH_anon_WITH_AES_256_CBC_SHA256" },

	/* Camellia cipher suites (RFC 5932) */
	{ 0x0041,	1, STRONG,	"RSA_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0042,	1, STRONG,	"DH_DSS_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0043,	1, STRONG,	"DH_RSA_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0044,	1, STRONG,	"DHE_DSS_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0045,	1, STRONG,	"DHE_RSA_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0046,	1, STRONG,	"DH_anon_WITH_CAMELLIA_128_CBC_SHA" },
	{ 0x0084,	1, STRONG,	"RSA_WITH_CAMELLIA_256_CBC_SHA" },
	{ 0x0085,	1, STRONG,	"DH_DSS_WITH_CAMELLIA_256_CBC_SHA" },
	{ 0x0086,	1, STRONG,	"DH_RSA_WITH_CAMELLIA_256_CBC_SHA" },
	{ 0x0087,	1, STRONG,	"DHE_DSS_WITH_CAMELLIA_256_CBC_SHA" },
	{ 0x0088,	1, STRONG,	"DHE_RSA_WITH_CAMELLIA_256_CBC_SHA" },
	{ 0x0089,	1, STRONG,	"DH_anon_WITH_CAMELLIA_256_CBC_SHA" },

	/* http://www.iana.org/assignments/tls-parameters/ */
	{ 0x008A,	0, STRONG,	"TLS_PSK_WITH_RC4_128_SHA" },
	{ 0x008B,	1, STRONG,	"TLS_PSK_WITH_3DES_EDE_CBC_SHA" },
	{ 0x008C,	1, STRONG,	"TLS_PSK_WITH_AES_128_CBC_SHA" },
	{ 0x008D,	1, STRONG,	"TLS_PSK_WITH_AES_256_CBC_SHA" },
	{ 0x008E,	0, STRONG,	"TLS_DHE_PSK_WITH_RC4_128_SHA" },
	{ 0x008F,	1, STRONG,	"TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0090,	1, STRONG,	"TLS_DHE_PSK_WITH_AES_128_CBC_SHA" },
	{ 0x0091,	1, STRONG,	"TLS_DHE_PSK_WITH_AES_256_CBC_SHA" },
	{ 0x0092,	0, STRONG,	"TLS_RSA_PSK_WITH_RC4_128_SHA" },
	{ 0x0093,	1, STRONG,	"TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA" },
	{ 0x0094,	1, STRONG,	"TLS_RSA_PSK_WITH_AES_128_CBC_SHA" },
	{ 0x0095,	1, STRONG,	"TLS_RSA_PSK_WITH_AES_256_CBC_SHA" },
	{ 0x0096,	1, STRONG,	"TLS_RSA_WITH_SEED_CBC_SHA" },
	{ 0x0097,	1, STRONG,	"TLS_DH_DSS_WITH_SEED_CBC_SHA" },
	{ 0x0098,	1, STRONG,	"TLS_DH_RSA_WITH_SEED_CBC_SHA" },
	{ 0x0099,	1, STRONG,	"TLS_DHE_DSS_WITH_SEED_CBC_SHA" },
	{ 0x009A,	1, STRONG,	"TLS_DHE_RSA_WITH_SEED_CBC_SHA" },
	{ 0x009B,	1, STRONG,	"TLS_DH_anon_WITH_SEED_CBC_SHA" },
	{ 0x009C,	0, STRONG,	"TLS_RSA_WITH_AES_128_GCM_SHA256" },
	{ 0x009D,	0, STRONG,	"TLS_RSA_WITH_AES_256_GCM_SHA384" },
	{ 0x009E,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_128_GCM_SHA256" },
	{ 0x009F,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_256_GCM_SHA384" },
	{ 0x00A0,	0, STRONG,	"TLS_DH_RSA_WITH_AES_128_GCM_SHA256" },
	{ 0x00A1,	0, STRONG,	"TLS_DH_RSA_WITH_AES_256_GCM_SHA384" },
	{ 0x00A2,	0, STRONG,	"TLS_DHE_DSS_WITH_AES_128_GCM_SHA256" },
	{ 0x00A3,	0, STRONG,	"TLS_DHE_DSS_WITH_AES_256_GCM_SHA384" },
	{ 0x00A4,	0, STRONG,	"TLS_DH_DSS_WITH_AES_128_GCM_SHA256" },
	{ 0x00A5,	0, STRONG,	"TLS_DH_DSS_WITH_AES_256_GCM_SHA384" },
	{ 0x00A6,	0, STRONG,	"TLS_DH_anon_WITH_AES_128_GCM_SHA256" },
	{ 0x00A7,	0, STRONG,	"TLS_DH_anon_WITH_AES_256_GCM_SHA384" },
	{ 0x00A8,	0, STRONG,	"TLS_PSK_WITH_AES_128_GCM_SHA256" },
	{ 0x00A9,	0, STRONG,	"TLS_PSK_WITH_AES_256_GCM_SHA384" },
	{ 0x00AA,	0, STRONG,	"TLS_DHE_PSK_WITH_AES_128_GCM_SHA256" },
	{ 0x00AB,	0, STRONG,	"TLS_DHE_PSK_WITH_AES_256_GCM_SHA384" },
	{ 0x00AC,	0, STRONG,	"TLS_RSA_PSK_WITH_AES_128_GCM_SHA256" },
	{ 0x00AD,	0, STRONG,	"TLS_RSA_PSK_WITH_AES_256_GCM_SHA384" },
	{ 0x00AE,	1, STRONG,	"TLS_PSK_WITH_AES_128_CBC_SHA256" },
	{ 0x00AF,	1, STRONG,	"TLS_PSK_WITH_AES_256_CBC_SHA384" },
	{ 0x00B0,	0, CLEAR,	"TLS_PSK_WITH_NULL_SHA256" },
	{ 0x00B1,	0, CLEAR,	"TLS_PSK_WITH_NULL_SHA384" },
	{ 0x00B2,	1, STRONG,	"TLS_DHE_PSK_WITH_AES_128_CBC_SHA256" },
	{ 0x00B3,	1, STRONG,	"TLS_DHE_PSK_WITH_AES_256_CBC_SHA384" },
	{ 0x00B4,	0, CLEAR,	"TLS_DHE_PSK_WITH_NULL_SHA256" },
	{ 0x00B5,	0, CLEAR,	"TLS_DHE_PSK_WITH_NULL_SHA384" },
	{ 0x00B6,	1, STRONG,	"TLS_RSA_PSK_WITH_AES_128_CBC_SHA256" },
	{ 0x00B7,	1, STRONG,	"TLS_RSA_PSK_WITH_AES_256_CBC_SHA384" },
	{ 0x00B8,	0, CLEAR,	"TLS_RSA_PSK_WITH_NULL_SHA256" },
	{ 0x00B9,	0, CLEAR,	"TLS_RSA_PSK_WITH_NULL_SHA384" },
	{ 0x00BA,	1, STRONG,	"TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00BB,	1, STRONG,	"TLS_DH_DSS_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00BC,	1, STRONG,	"TLS_DH_RSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00BD,	1, STRONG,	"TLS_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00BE,	1, STRONG,	"TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00BF,	1, STRONG,	"TLS_DH_anon_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0x00C0,	1, STRONG,	"TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256" },
	{ 0x00C1,	1, STRONG,	"TLS_DH_DSS_WITH_CAMELLIA_256_CBC_SHA256" },
	{ 0x00C2,	1, STRONG,	"TLS_DH_RSA_WITH_CAMELLIA_256_CBC_SHA256" },
	{ 0x00C3,	1, STRONG,	"TLS_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA256" },
	{ 0x00C4,	1, STRONG,	"TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA256" },
	{ 0x00C5,	1, STRONG,	"TLS_DH_anon_WITH_CAMELLIA_256_CBC_SHA256" },

	/**
	 * Fake suite to indicate support of secure renegotiation (RFC5746)
	 * for servers that fail handshakes with unknown TLS extensions
	{ 0x00FF,	0, CLEAR,	"TLS_EMPTY_RENEGOTIATION_INFO_SCSV" },
	 */

	/** http://tools.ietf.org/html/draft-chudov-cryptopro-cptls-04 */
	{ 0x0080,	0, STRONG,	"TLS_GOSTR341094_WITH_28147_CNT_IMIT" },
	{ 0x0081,	0, STRONG,	"TLS_GOSTR341001_WITH_28147_CNT_IMIT" },
	{ 0x0082,	0, STRONG,	"TLS_GOSTR341094_WITH_NULL_GOSTR3411" },
	{ 0x0083,	0, STRONG,	"TLS_GOSTR341001_WITH_NULL_GOSTR3411" },

	{ 0xC001,	0, CLEAR,	"TLS_ECDH_ECDSA_WITH_NULL_SHA" },
	{ 0xC002,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_RC4_128_SHA" },
	{ 0xC003,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC004,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA" },
	{ 0xC005,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA" },
	{ 0xC006,	0, CLEAR,	"TLS_ECDHE_ECDSA_WITH_NULL_SHA" },
	{ 0xC007,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_RC4_128_SHA" },
	{ 0xC008,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC009,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA" },
	{ 0xC00A,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA" },
	{ 0xC00B,	0, CLEAR,	"TLS_ECDH_RSA_WITH_NULL_SHA" },
	{ 0xC00C,	0, STRONG,	"TLS_ECDH_RSA_WITH_RC4_128_SHA" },
	{ 0xC00D,	1, STRONG,	"TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC00E,	1, STRONG,	"TLS_ECDH_RSA_WITH_AES_128_CBC_SHA" },
	{ 0xC00F,	1, STRONG,	"TLS_ECDH_RSA_WITH_AES_256_CBC_SHA" },
	{ 0xC010,	0, CLEAR,	"TLS_ECDHE_RSA_WITH_NULL_SHA" },
	{ 0xC011,	0, STRONG,	"TLS_ECDHE_RSA_WITH_RC4_128_SHA" },
	{ 0xC012,	1, STRONG,	"TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC013,	1, STRONG,	"TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA" },
	{ 0xC014,	1, STRONG,	"TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA" },
	{ 0xC015,	0, CLEAR,	"TLS_ECDH_anon_WITH_NULL_SHA" },
	{ 0xC016,	0, STRONG,	"TLS_ECDH_anon_WITH_RC4_128_SHA" },
	{ 0xC017,	1, STRONG,	"TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC018,	1, STRONG,	"TLS_ECDH_anon_WITH_AES_128_CBC_SHA" },
	{ 0xC019,	1, STRONG,	"TLS_ECDH_anon_WITH_AES_256_CBC_SHA" },
	{ 0xC01A,	1, STRONG,	"TLS_SRP_SHA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC01B,	1, STRONG,	"TLS_SRP_SHA_RSA_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC01C,	1, STRONG,	"TLS_SRP_SHA_DSS_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC01D,	1, STRONG,	"TLS_SRP_SHA_WITH_AES_128_CBC_SHA" },
	{ 0xC01E,	1, STRONG,	"TLS_SRP_SHA_RSA_WITH_AES_128_CBC_SHA" },
	{ 0xC01F,	1, STRONG,	"TLS_SRP_SHA_DSS_WITH_AES_128_CBC_SHA" },
	{ 0xC020,	1, STRONG,	"TLS_SRP_SHA_WITH_AES_256_CBC_SHA" },
	{ 0xC021,	1, STRONG,	"TLS_SRP_SHA_RSA_WITH_AES_256_CBC_SHA" },
	{ 0xC022,	1, STRONG,	"TLS_SRP_SHA_DSS_WITH_AES_256_CBC_SHA" },
	{ 0xC023,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256" },
	{ 0xC024,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384" },
	{ 0xC025,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256" },
	{ 0xC026,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384" },
	{ 0xC027,	1, STRONG,	"TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256" },
	{ 0xC028,	1, STRONG,	"TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384" },
	{ 0xC029,	1, STRONG,	"TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256" },
	{ 0xC02A,	1, STRONG,	"TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384" },
	{ 0xC02B,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256" },
	{ 0xC02C,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384" },
	{ 0xC02D,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256" },
	{ 0xC02E,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384" },
	{ 0xC02F,	0, STRONG,	"TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256" },
	{ 0xC030,	0, STRONG,	"TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384" },
	{ 0xC031,	0, STRONG,	"TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256" },
	{ 0xC032,	0, STRONG,	"TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384" },
	{ 0xC033,	0, STRONG,	"TLS_ECDHE_PSK_WITH_RC4_128_SHA" },
	{ 0xC034,	1, STRONG,	"TLS_ECDHE_PSK_WITH_3DES_EDE_CBC_SHA" },
	{ 0xC035,	1, STRONG,	"TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA" },
	{ 0xC036,	1, STRONG,	"TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA" },
	{ 0xC037,	1, STRONG,	"TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA256" },
	{ 0xC038,	1, STRONG,	"TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA384" },
	{ 0xC039,	0, CLEAR,	"TLS_ECDHE_PSK_WITH_NULL_SHA" },
	{ 0xC03A,	0, CLEAR,	"TLS_ECDHE_PSK_WITH_NULL_SHA256" },
	{ 0xC03B,	0, CLEAR,	"TLS_ECDHE_PSK_WITH_NULL_SHA384" },
	{ 0xC03C,	1, STRONG,	"TLS_RSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC03D,	1, STRONG,	"TLS_RSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC03E,	1, STRONG,	"TLS_DH_DSS_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC03F,	1, STRONG,	"TLS_DH_DSS_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC040,	1, STRONG,	"TLS_DH_RSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC041,	1, STRONG,	"TLS_DH_RSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC042,	1, STRONG,	"TLS_DHE_DSS_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC043,	1, STRONG,	"TLS_DHE_DSS_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC044,	1, STRONG,	"TLS_DHE_RSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC045,	1, STRONG,	"TLS_DHE_RSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC046,	1, STRONG,	"TLS_DH_anon_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC047,	1, STRONG,	"TLS_DH_anon_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC048,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC049,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC04A,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC04B,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC04C,	1, STRONG,	"TLS_ECDHE_RSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC04D,	1, STRONG,	"TLS_ECDHE_RSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC04E,	1, STRONG,	"TLS_ECDH_RSA_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC04F,	1, STRONG,	"TLS_ECDH_RSA_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC050,	0, STRONG,	"TLS_RSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC051,	0, STRONG,	"TLS_RSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC052,	0, STRONG,	"TLS_DHE_RSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC053,	0, STRONG,	"TLS_DHE_RSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC054,	0, STRONG,	"TLS_DH_RSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC055,	0, STRONG,	"TLS_DH_RSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC056,	0, STRONG,	"TLS_DHE_DSS_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC057,	0, STRONG,	"TLS_DHE_DSS_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC058,	0, STRONG,	"TLS_DH_DSS_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC059,	0, STRONG,	"TLS_DH_DSS_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC05A,	0, STRONG,	"TLS_DH_anon_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC05B,	0, STRONG,	"TLS_DH_anon_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC05C,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC05D,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC05E,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC05F,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC060,	0, STRONG,	"TLS_ECDHE_RSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC061,	0, STRONG,	"TLS_ECDHE_RSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC062,	0, STRONG,	"TLS_ECDH_RSA_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC063,	0, STRONG,	"TLS_ECDH_RSA_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC064,	1, STRONG,	"TLS_PSK_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC065,	1, STRONG,	"TLS_PSK_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC066,	1, STRONG,	"TLS_DHE_PSK_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC067,	1, STRONG,	"TLS_DHE_PSK_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC068,	1, STRONG,	"TLS_RSA_PSK_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC069,	1, STRONG,	"TLS_RSA_PSK_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC06A,	0, STRONG,	"TLS_PSK_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC06B,	0, STRONG,	"TLS_PSK_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC06C,	0, STRONG,	"TLS_DHE_PSK_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC06D,	0, STRONG,	"TLS_DHE_PSK_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC06E,	0, STRONG,	"TLS_RSA_PSK_WITH_ARIA_128_GCM_SHA256" },
	{ 0xC06F,	0, STRONG,	"TLS_RSA_PSK_WITH_ARIA_256_GCM_SHA384" },
	{ 0xC070,	1, STRONG,	"TLS_ECDHE_PSK_WITH_ARIA_128_CBC_SHA256" },
	{ 0xC071,	1, STRONG,	"TLS_ECDHE_PSK_WITH_ARIA_256_CBC_SHA384" },
	{ 0xC072,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC073,	1, STRONG,	"TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC074,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC075,	1, STRONG,	"TLS_ECDH_ECDSA_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC076,	1, STRONG,	"TLS_ECDHE_RSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC077,	1, STRONG,	"TLS_ECDHE_RSA_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC078,	1, STRONG,	"TLS_ECDH_RSA_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC079,	1, STRONG,	"TLS_ECDH_RSA_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC07A,	0, STRONG,	"TLS_RSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC07B,	0, STRONG,	"TLS_RSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC07C,	0, STRONG,	"TLS_DHE_RSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC07D,	0, STRONG,	"TLS_DHE_RSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC07E,	0, STRONG,	"TLS_DH_RSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC07F,	0, STRONG,	"TLS_DH_RSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC080,	0, STRONG,	"TLS_DHE_DSS_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC081,	0, STRONG,	"TLS_DHE_DSS_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC082,	0, STRONG,	"TLS_DH_DSS_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC083,	0, STRONG,	"TLS_DH_DSS_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC084,	0, STRONG,	"TLS_DH_anon_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC085,	0, STRONG,	"TLS_DH_anon_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC086,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC087,	0, STRONG,	"TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC088,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC089,	0, STRONG,	"TLS_ECDH_ECDSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC08A,	0, STRONG,	"TLS_ECDHE_RSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC08B,	0, STRONG,	"TLS_ECDHE_RSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC08C,	0, STRONG,	"TLS_ECDH_RSA_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC08D,	0, STRONG,	"TLS_ECDH_RSA_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC08E,	0, STRONG,	"TLS_PSK_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC08F,	0, STRONG,	"TLS_PSK_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC090,	0, STRONG,	"TLS_DHE_PSK_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC091,	0, STRONG,	"TLS_DHE_PSK_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC092,	0, STRONG,	"TLS_RSA_PSK_WITH_CAMELLIA_128_GCM_SHA256" },
	{ 0xC093,	0, STRONG,	"TLS_RSA_PSK_WITH_CAMELLIA_256_GCM_SHA384" },
	{ 0xC094,	1, STRONG,	"TLS_PSK_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC095,	1, STRONG,	"TLS_PSK_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC096,	1, STRONG,	"TLS_DHE_PSK_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC097,	1, STRONG,	"TLS_DHE_PSK_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC098,	1, STRONG,	"TLS_RSA_PSK_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC099,	1, STRONG,	"TLS_RSA_PSK_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC09A,	1, STRONG,	"TLS_ECDHE_PSK_WITH_CAMELLIA_128_CBC_SHA256" },
	{ 0xC09B,	1, STRONG,	"TLS_ECDHE_PSK_WITH_CAMELLIA_256_CBC_SHA384" },
	{ 0xC09C,	0, STRONG,	"TLS_RSA_WITH_AES_128_CCM" },
	{ 0xC09D,	0, STRONG,	"TLS_RSA_WITH_AES_256_CCM" },
	{ 0xC09E,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_128_CCM" },
	{ 0xC09F,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_256_CCM" },
	{ 0xC0A0,	0, STRONG,	"TLS_RSA_WITH_AES_128_CCM_8" },
	{ 0xC0A1,	0, STRONG,	"TLS_RSA_WITH_AES_256_CCM_8" },
	{ 0xC0A2,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_128_CCM_8" },
	{ 0xC0A3,	0, STRONG,	"TLS_DHE_RSA_WITH_AES_256_CCM_8" },
	{ 0xC0A4,	0, STRONG,	"TLS_PSK_WITH_AES_128_CCM" },
	{ 0xC0A5,	0, STRONG,	"TLS_PSK_WITH_AES_256_CCM" },
	{ 0xC0A6,	0, STRONG,	"TLS_DHE_PSK_WITH_AES_128_CCM" },
	{ 0xC0A7,	0, STRONG,	"TLS_DHE_PSK_WITH_AES_256_CCM" },
	{ 0xC0A8,	0, STRONG,	"TLS_PSK_WITH_AES_128_CCM_8" },
	{ 0xC0A9,	0, STRONG,	"TLS_PSK_WITH_AES_256_CCM_8" },
	{ 0xC0AA,	0, STRONG,	"TLS_PSK_DHE_WITH_AES_128_CCM_8" },
	{ 0xC0AB,	0, STRONG,	"TLS_PSK_DHE_WITH_AES_256_CCM_8" }
};

#endif
