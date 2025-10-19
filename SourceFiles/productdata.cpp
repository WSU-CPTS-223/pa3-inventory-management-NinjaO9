#include "../HeaderFiles/productdata.hpp"

ostream& operator<<(ostream &lhs, const ProductData &rhs)
{
    lhs << "Uniqe ID: " << rhs.get_uniqid() << " Product Name: " << rhs.get_productname();
    return lhs;
}
ProductData::ProductData(string attr[])
{
    _UniqId = attr[UNIQ_ID]; 
    _ProductName = attr[PRODUCT_NAME]; 
    _BrandName = attr[BRAND_NAME];
    _Asin = attr[ASIN];
    _Categories = attr[CATEGORY];
    _UpcEanCode = attr[UPC_EAN_CODE];
    _ListPrice = attr[LIST_PRICE]; 
    _SellingPrice = attr[SELLING_PRICE];
    _Quantity = attr[QUANTITY];
    _ModelNumber = attr[MODEL_NUMBER];
    _AboutProduct = attr[ABOUT_PRODUCT];
    _ProductSpecifications = attr[PRODUCT_SPECIFICATION];
    _TechnicalDetails = attr[TECHNICAL_DETAILS];
    _ShippingWeight = attr[SHIPPING_WEIGHT];
    _ProductDimensions = attr[PRODUCT_DIMENSIONS];
    _Image = attr[IMAGE];
    _Variants = attr[VARIANTS];
    _Sku = attr[SKU];
    _ProductUrl = attr[PRODUCT_URL];
    _Stock = attr[STOCK];
    _ProductDetails = attr[PRODUCT_DETAILS];
    _Dimensions = attr[DIMENSIONS];
    _Color = attr[COLOR];
    _Ingredients = attr[INGREDIENTS];
    _DirectionToUse = attr[DIRECTION_TO_USE];
    _IsAmazonSeller = attr[IS_AMAZON_SELLER];
    _SizeQuantityVariant = attr[SIZE_QUANTITY_VARIANT];
    _ProductDescription = attr[PRODUCT_DESCRIPTION];
}